# -*- coding: utf-8 -*-

import mechanize
from BeautifulSoup import BeautifulSoup
import re
import urllib

pageLink = []
f = file('/home/king/imageName.txt','w')
def downloadImage(soup):
	imgClass = soup.findAll(attrs={"class":"BDE_Image"})
	if imgClass == None:
		print "no"
	for img in imgClass:
		imgSrc = img.get('src')
		imgSrc = str(imgSrc)
		title = imgSrc.split('/')[-1]
		urllib.urlretrieve(imgSrc,"/home/king/tiebaImg/"+title)
		f.write(title+'\n')


def totalPage(soup):
	lastLink = soup.findAll(attrs={"class":"last"})
	href = lastLink[1].get('href')
	num = re.findall(r"[0-9]+",href)
	return long(num[0])

def findThreadPageNum(soup):
	link = soup.find(attrs={"class":"l_pager"})
	if link != None:
		link = link.contents
		pageNum = link[-1].get('href')
		pageNum = re.findall(r"pn=[0-9]+",str(pageNum))
		pageNum = re.findall(r"[0-9]+",pageNum[0])
		return int(pageNum[0])
	return 1

def scrapThread(url):
	base = "http://tieba.baidu.com"
	threadUrl = base+url
	print "thread:"+threadUrl

	threadBr = mechanize.Browser()
	data = threadBr.open(threadUrl).get_data()
	soup = BeautifulSoup(data)
	threadPageNum = findThreadPageNum(soup)
	print threadPageNum
	page = 1
	while page <= threadPageNum:
		if page == 1:
			downloadImage(soup)
		else:
			pageUrl = threadUrl+"?pn="+str(page)
			data = threadBr.open(pageUrl).get_data()
			soup = BeautifulSoup(data)
			downloadImage(soup)
		page = page+1

def scrap(soup):
	threadLink = soup.findAll(attrs={"class":"thread_title"})
	print len(threadLink)
	for anchor in threadLink:
		thread = anchor.contents[1].get('href')
		if thread not in pageLink:
			thread = str(thread)
			pageLink.append(thread)
			scrapThread(thread)


def main():
	baseUrl = "http://tieba.baidu.com/f?kw=%BA%DA%CB%BF"

	br = mechanize.Browser()
	data = br.open(baseUrl).get_data()
	soup = BeautifulSoup(data)
	pageNum = totalPage(soup)
	baseNum = 0
	while baseNum <= pageNum:
		if baseNum == 0:
			print 0
			scrap(soup)
		else:
			url = baseUrl+"&pn="+str(baseNum)
			data = br.open(url).get_data()#抓取每个整页的数据
			soup = BeautifulSoup(data)#转成soup
			#print url
			scrap(soup)
		baseNum = baseNum + 50

if __name__ == "__main__":
	main()

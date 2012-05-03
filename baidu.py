# -*- coding: utf-8 -*-

import mechanize
from BeautifulSoup import BeautifulSoup
import re
import urllib
import cookielib


pageLink = []
f = file('/home/king/imageName.txt','w')
br = mechanize.Browser()
def login():
	cj = cookielib.LWPCookieJar()
	br.set_cookiejar(cj)

	br.set_handle_redirect(True)
	br.set_handle_gzip(True)
	br.set_handle_equiv(True)
	br.set_handle_referer(True)
	br.set_handle_robots(False)

	#br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
	br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; Linux x86_64; rv:2.0) Gecko/20100101 Firefox/4.0')]
	r = br.open('https://passport.baidu.com/?login&tpl=mn')
	br.select_form(nr=0)
	br.form['username']='jkfsiwa'
	br.form.find_control("password").readonly = False
	br.form['password']='qwerty'
	br.submit


def downloadImage(soup):
	imgClass = soup.findAll(attrs={"class":"BDE_Image"})
	if imgClass == None:
		print "no"
	for img in imgClass:
		imgSrc = img.get('src')
		imgSrc = str(imgSrc)
		print imgSrc
	#	pirnt imgSrc
		title = imgSrc.split('/')[-1]
		print title
		urllib.urlretrieve(imgSrc,"/home/king/tiebaImg/"+title)
		print "Download..."
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
	threadUrl = base+url+"?see_lz=1"
	print "thread:"+threadUrl

	#threadBr = mechanize.Browser()
	data = br.open(threadUrl).get_data()
	soup = BeautifulSoup(data)
	threadPageNum = findThreadPageNum(soup)
	print threadPageNum
	page = 9
	print 'page: '+str(page)
	while page <= threadPageNum:
		if page == 1:
			downloadImage(soup)
		else:
			pageUrl = threadUrl+"&pn="+str(page)
			data = br.open(pageUrl).get_data()
			soup = BeautifulSoup(data)
			downloadImage(soup)
		page = page+1
		print 'page: '+str(page)

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
	login()
	baseUrl = "http://tieba.baidu.com/f?kw=%BA%DA%CB%BF"
	data = br.open(baseUrl).get_data()
	soup = BeautifulSoup(data)
	pageNum = totalPage(soup)
	baseNum = 100
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

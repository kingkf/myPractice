# -*- coding: utf-8 -*-
import mechanize
import cookielib

br = mechanize.Browser()

#Cookie Jar
cj = cookielib.LWPCookieJar()
br.set_cookiejar(cj)

#Browser_options
br.set_handle_equiv(True)
br.set_handle_gzip(True)
br.set_handle_redirect(True)
br.set_handle_referer(True)
br.set_handle_robots(False)

#br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; Linux x86_64; rv:2.0) Gecko/20100101 Firefox/4.0')]

r = br.open('https://passport.baidu.com/?login&tpl=mn')

br.select_form(nr=0)
br.form['username']='科比vs迦楼罗'
br.form.find_control("password").readonly = False
br.form['password']='j1k2f3abc'
br.submit()

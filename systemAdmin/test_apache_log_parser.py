#!/usr/bin/env python

import unittest
import apache_log_parser_split

class TestApacheLogParser(unittest.TestCase):

	def setUp(self):
		pass

	def testCombineExample(self):
		common_log_entry = '127.0.0.1 - - [24/Apr/2012:21:44:02 +0800] "GET / HTTP/1.1" 200 484 "-" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"'
		self.assertEqual(apache_log_parser_split.dictify_logline(common_log_entry),
				{'remote_host': '127.0.0.1', 'status': '200', 'bytes_sent': '484'})
	
	
	
	def testExtraWhitespace(self):
		common_log_entry = '127.0.0.1    -    - [24/Apr/2012:21:44:02 +0800] "GET / HTTP/1.1" 200 484 "-" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"'
		self.assertEqual(apache_log_parser_split.dictify_logline(common_log_entry),
				{'remote_host': '127.0.0.1', 'status': '200', 'bytes_sent': '484'})

	def testMalformed(self):
		common_log_entry = '127.0.0.1    -    - [24/Apr/2012:21:44:02 +0800] "GET /a/a b HTTP/1.1" 200 484 "-" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"'
		self.assertEqual(apache_log_parser_split.dictify_logline(common_log_entry),
				{'remote_host': '127.0.0.1', 'status': '200', 'bytes_sent': '484'})


if __name__ == "__main__":
	unittest.main()



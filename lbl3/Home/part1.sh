#!/bin/bash

declare -a sitesList=('www.google.com' 'www.google.co.uk' 'www.amazon.ca' 'www.hcmut.edu.vn' 'www.aptech-education.com' 'web.mit.edu' 'ebay.vn' 'en-gb.facebook.com' 'twitter.com' 'weibo.com' 'www.bbc.co.uk' 'tuoitrenews.vn' 'abc.go.com' 'www.viqu.co.uk' 'www.dcs.gla.ac.uk' 'www.sony.co.jp' 'www.fpt-software.com' 'news.gov.scot')
> ipList.txt
for i in "${sitesList[@]}"
do
    ./dnslookup $i >> ipList.txt
done
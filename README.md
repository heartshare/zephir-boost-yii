BoostYii
========

This is a yii2 boost extension code by zephir language,if u install this extension on your php machine , u will get a better yii2 performance.  

This is a funny project just for me or demo , I will not continue develpment this project.

I only implement a class boostyii/base/Object , but this proved to be enough to improve performance.


## Build Require ##
U need install zephir in ur machine. see https://github.com/phalcon/zephir

## Directory ##

- extension-src : zephir code , u can build extension by zephir
- php-src : your yii2 index.php need include BoostYiiLoader.php

## Install Tips ##
If u build boostyii success, u need add extension=boostyii.so after extension=json.so in your php ini then restart web server or php-fpm.

## How to use ##

- copy php-src to ur yii project , and rename it like "boostyii"
- Add a line in ur index.php , look example code :

~~~php
    <?php
    
    // comment out the following two lines when deployed to production
    defined('YII_DEBUG') or define('YII_DEBUG', true);
    defined('YII_ENV') or define('YII_ENV', 'dev');
    require(__DIR__ . '/../vendor/autoload.php');
    require(__DIR__ . '/../vendor/yiisoft/yii2/yii/Yii.php');
    // Add this line , we can get boost performance
    require(__DIR__ . '/../boostyii/BoostYiiLoader.php');
~~~


Is it easy ?

## Benchmark ##
CPU : Intel core2 E6750
OS : CentOS 6.5 64bit
PHP : 5.4.24

I use yii2 alpha and create a project from basic template,then create a index-boost.php use yiiboost. then use ab to test benchmark.... **9% faster !!!!!!**

ab -c 10 -t 10 http://localhost/boostyii/index.php

Document Path:          /boostyii/index.php
Document Length:        11208 bytes

Concurrency Level:      10
Time taken for tests:   10.000 seconds
Complete requests:      2336
Failed requests:        0
Write errors:           0
Total transferred:      27447386 bytes
HTML transferred:       26190080 bytes
Requests per second:    233.60 [#/sec] (mean)
Time per request:       42.809 [ms] (mean)
Time per request:       4.281 [ms] (mean, across all concurrent requests)
Transfer rate:          2680.37 [Kbytes/sec] received

ab -c 10 -t 10 http://localhost/boostyii/index-boost.php

Document Path:          /boostyii/index-boost.php
Document Length:        11244 bytes

Concurrency Level:      10
Time taken for tests:   10.002 seconds
Complete requests:      2545
Failed requests:        0
Write errors:           0
Total transferred:      29993920 bytes
HTML transferred:       28624172 bytes
Requests per second:    254.44 [#/sec] (mean)
Time per request:       39.302 [ms] (mean)
Time per request:       3.930 [ms] (mean, across all concurrent requests)
Transfer rate:          2928.40 [Kbytes/sec] received

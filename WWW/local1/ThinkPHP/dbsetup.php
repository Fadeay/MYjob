<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
$DB_USER = 'root';
$DB_PWD = '123444';
$DB_HOST = 'localhost';
$DB_NAME = 'MYWEB';

$name = 'adminmin';
$pass = md5(md5('adminmin'));

@$con=mysqli_connect($DB_HOST,$DB_USER,$DB_PWD) or die("<font color='red'>连接失败</br></font>");
@!mysqli_select_db($con,$DB_NAME)               or die("<font color='red'>数据库已存在</br></font>");
@mysqli_query($con,"CREATE DATABASE `MYWEB` CHARACTER SET `gbk`")     or die("<font color='red'>创建数据库失败</br></font>");
                                                echo "<font color='green'>创建数据库成功</br></font>";

$sql="CREATE TABLE `MYWEB`.`admin`(
      `id` int(3)NOT NULL AUTO_INCREMENT,
      `adminname` varchar(30) NOT NULL,
      `password` varchar(32) NOT NULL,
      `lastdate` int(10) NOT NULL,
      `lastip` varchar(15) NOT NULL,
      PRIMARY KEY (`id`))";
@mysqli_query($con,$sql)                        or die("<font color='red'>创建管理员表失败</br></font>");
                                                echo "<font color='green'>创建管理员表成功</br></font>";

$sql="CREATE TABLE `MYWEB`.`user`(
      `id` int(3)NOT NULL AUTO_INCREMENT,
      `username` varchar(30) NOT NULL,
      `password` varchar(32) NOT NULL,
      `lastdate` int(10) NOT NULL,
      `regdate` int(10) NOT NULL,
      `email` char(32) NOT NULL,
      PRIMARY KEY (`id`))";
@mysqli_query($con,$sql)                       or die("<font color='red'>创建用户表失败</br></font>");
                                                echo "<font color='green'>创建用户表成功</br></font>";

$sql="INSERT INTO `MYWEB`.`admin` (adminname, password, lastdate, lastip)
      VALUES (\"$name\", \"$pass\", 0, 0)";
@mysqli_query($con,$sql)                       or die("<font color='red'>插入初始管理员失败</br></font>");
                                                echo "<font color='green'>插入初始管理员成功</br></font>";
@mysqli_close($conn);
<?php
/**
 *	file name:	device_run.php
 *	author:		JungJaeJoon (rgbi3307@nate.com) on the www.kernel.bz
 *	comments:   device running
 */

$device = $_REQUEST["device"];
$run = $_REQUEST["run"];
//$DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];

/**
sudo vi /etc/sudoers
www-data ALL=NOPASSWD: ALL
#www-data ALL=NOPASSWD: /var/www/html/device_run, ./device_run

system("sudo whoami", $result); //must be root
//system("whoami", $result);
echo $result;
*/

include "./include/mysql.inc";
$dbName = "db_smart_home";
$isDebug = 0;	//mysql debugging 설정
//$dbLink = MysqlConnect($dbPort, $dbUser, $dbPass);		//mysql에 연결
//MysqlSelectdb($dbName);
$dbLink = MysqlConnect2($dbPort, $dbUser, $dbPass, $dbName);

//system("sudo ./device_run $device $run", $output);
$command = "sudo ./device_run $device $run";
exec($command, $output, $return);
//echo $command;
//echo $output;
//echo $return;
if ($isdebug) {
    while(list($idx, $msg) = each($output)) {
        echo("Result[$idx]: $msg<br>");
    }
    echo("Return: $return<br>");
}

if ($return == 255) {
    if ($device==0) $query = "UPDATE tbl_status SET status=$run, dtime=now() WHERE dno < 9;";
    else if ($device==10) $query = "UPDATE tbl_status SET status=$run, dtime=now() WHERE dno > 9;";
    else $query = "UPDATE tbl_status SET status=$run, dtime=now() WHERE dno=$device;";
    $result = MysqlQuery2($dbLink, $query, $isDebug);
} else {
    echo("An error occurred while exec()");
}

MysqlClose2($dbLink);

$location = "window.location.href = './index.php'";
echo ("<script language=javascript>$location;</script>");
?>

<?php
//-----------------------------------------------------------------------------
//	file name : ./include/mysql.inc
//	function  : MySQL 데이타베이스 작업 관련 모듈
//	updated   : 2000/03/10
//	author		: Jung,JaeJoon (rgbi3307@nate.com)
//	Copyrights: www.kernel.bz
//-----------------------------------------------------------------------------

//테이타베이스 변수 정의
//-----------------------------------------------------------------------------
$dbUser	= "root";
$dbPort = "localhost:3306";
$dbPass	= "kernel.bz";

//-----------------------------------------------------------------------------
//	MysqlError($code) : mysql error 처리 함수
//	$code = 0 : DB 연결 실패
//	$code = 1 : Table 연결 실패
//	$code = 2 : Query 실패
//-----------------------------------------------------------------------------
function MysqlError($code)
{
	switch($code)
	{
	case 0:
		echo "<font color=red>DB 연결 에러</font> 입니다. <br>
				잠시후에 연결을 시도해보시고 <br>
				그래도 연결이 되지 않을경우 시스템 관리자에게 <br>
				문의해 주세요 !!<br>";
		echo "<form><input type=button value=되돌아가기 onClick=history.back()></form>";
		exit;
		break;

	case 1:
		echo "<font color=red>테이블 연결 에러</font> 입니다. <br>
				잠시후에 연결을 시도해 보시고 <br>
				그래도 연결이 되지 않을경우 시스템 관리자에게<br>
				문의해 주세요 !!<br>";
		echo "<form><input type=button value=되돌아가기 onClick=history.back()></form>";
		exit;
		break;

	case 2:
		echo "<font color=red>쿼리 실패</font> 입니다. <br>
               잠시후에 연결을 시도해 보시고 <br>
               그래도 연결이 되지 않을경우 시스템 관리자에게<br>
               문의해 주세요 !!<br>";
        echo "<form><input type=button value=되돌아가기 onClick=history.back()></form>";
        exit;
        break;
    }//end of switch
}

// mysql 데이타베이스에 연결하는 함수
//-----------------------------------------------------------------------------
function MysqlConnect($port, $user, $passwd)
{
	$connection = mysql_connect($port, $user, $passwd);
	if (!$connection) {
		MysqlError(0);
	}
	return $connection;
}

function MysqlConnect2($port, $user, $passwd, $db)
{
	$connection = mysqli_connect($port, $user, $passwd, $db);
	if (!$connection) {
		MysqlError(0);
	}
	return $connection;
}

// mysql 서버에 연결성공후 테이블에 연결시도 하는 함수
//-----------------------------------------------------------------------------
function MysqlSelectdb($dbname)
{
    $setdb = mysql_select_db($dbname);
    if (!$setdb) {
        MysqlError(1);
    }
    return $setdb;
}

//-----------------------------------------------------------------------------
//	Function Name : mquery
//	Desc :  연결된 테이블에 쿼리를 줘서 결과 치를 얻어내는 함수
//	argument : $query : mysql query SQL 문
//			   $isdebug : 디버깅시 sql 문을 출력함 , 1이면 출력, 0이면 출력한함
//			   $debugtxt : sql 문앞에 붙을 문장
//-----------------------------------------------------------------------------
function MysqlQuery($query, $isdebug = 0, $debugtxt = "")
{
	if ( $isdebug == 1 ) {
		echo $debugtxt.$query."<br>" ;
	}

    $result = mysql_query($query);

    if (!$result) {
        MysqlError(2);
     }
     return $result;
}

function MysqlQuery2($connection, $query, $isdebug = 0, $debugtxt = "")
{
	if ( $isdebug == 1 ) {
		echo $debugtxt.$query."<br>" ;
	}

    $result = mysqli_query($connection, $query);

    if (!$result) {
        MysqlError(2);
     }
     return $result;
}

// 튜플의 숫자를 얻어내는 함수
//-----------------------------------------------------------------------------
function MysqlNumRows($result)
{
    $total_tuple = mysql_num_rows($result);

    return $total_tuple;
}

function MysqlNumRows2($result)
{
    $total_tuple = mysqli_num_rows($result);

    return $total_tuple;
}

function MysqlClose($link)
{
    mysql_close($link);
}

function MysqlClose2($link)
{
    mysqli_close($link);
}

?>

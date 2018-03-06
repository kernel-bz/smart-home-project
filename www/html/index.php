<?php
/**
 *	file name:	index.php
 *	author:		JungJaeJoon (rgbi3307@nate.com) on the www.kernel.bz
 *	comments:   SmartHomeM Main WebPage
 */

//$return = $_REQUEST["return"];

$device_data = array( 0, 0, 0, 0 );
$command = "sudo ./device_data_get";
exec($command, $output, $return);
if ($return=255) {
    while(list($idx, $msg) = each($output)) {
        //echo("Result[$idx]: $msg<br>");
        if ($idx >= 2) {
            $dno = $idx - 2;
            $device_data[$dno] = $msg;
        }
    }
}

$bgv = array('#595959'
            ,'#595959','#595959','#595959'
            ,'#595959','#595959','#595959'
            ,'#595959','#595959','#595959'
            ,'#595959','#595959','#595959'
            ,'#595959','#595959','#595959' );
$bgc = array('#FFFF99'
            ,'#FF66FF','#00B0F0','#FF6600'
            ,'#FFCC00','#00B050','#66FF33'
            ,'#92CDDC','#00CC99','#FFFF99'
            ,'#CC9900','#CC66FF','#CC66FF'
            ,'#CC66FF','#CC66FF','#CC66FF' );
$fgv = array('#FFFFFF'
            ,'#FFFFFF','#FFFFFF','#FFFFFF'
            ,'#FFFFFF','#FFFFFF','#FFFFFF'
            ,'#FFFFFF','#FFFFFF','#FFFFFF'
            ,'#FFFFFF','#FFFFFF','#FFFFFF'
            ,'#FFFFFF','#FFFFFF','#FFFFFF' );
$fgc = array('#000000'
            ,'#000000','#000000','#000000'
            ,'#000000','#000000','#000000'
            ,'#000000','#000000','#000000'
            ,'#000000','#000000','#000000'
            ,'#000000','#000000','#000000' );
$dsw = array( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );

include "./include/mysql.inc";
$dbName = "db_smart_home";
$isDebug = 0;	//mysql debugging 설정
$dbLink = MysqlConnect2($dbPort, $dbUser, $dbPass, $dbName);

$query = "Select * From tbl_status;";
$result = MysqlQuery2($dbLink, $query, $isDebug);
$total = mysqli_affected_rows($dbLink);
for ($i=0; $i < $total; $i++)
{
    mysqli_data_seek($result, $i);
    //$record = mysqli_fetch_row($result);
    $record = mysqli_fetch_assoc($result);
    $dno = $record['dno'];
    $status = $record['status'];
    //echo("dno=$dno, status=$status<br>");
    $bgv[$dno] = ($status) ? $bgc[$dno] : $bgv[$dno];
    $fgv[$dno] = ($status) ? $fgc[$dno] : $fgv[$dno];
    $dsw[$dno] = ($status) ? 0 : 1;
}
mysqli_free_result($result);

?>

<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=utf-8">
<meta name="viewport" content="user-scalable=no, initial-scale=1.0,
        maximum-scale=1.0, minimum-scale=1.0, width=device-width">
<style>
<!--
 /* Font Definitions */
 @font-face
	{font-family:"맑은 고딕";
	panose-1:2 11 5 3 2 0 0 2 0 4;}
@font-face
	{font-family:"\@맑은 고딕";
	panose-1:2 11 5 3 2 0 0 2 0 4;}
 /* Style Definitions */
 p.MsoNormal, li.MsoNormal, div.MsoNormal
	{margin-top:0cm;
	margin-right:0cm;
	margin-bottom:10.0pt;
	margin-left:0cm;
	text-align:justify;
	text-justify:inter-ideograph;
	line-height:115%;
	text-autospace:none;
	word-break:break-hangul;
	font-size:10.0pt;
	font-family:"맑은 고딕";}
p.MsoHeader, li.MsoHeader, div.MsoHeader
	{mso-style-link:"머리글 Char";
	margin-top:0cm;
	margin-right:0cm;
	margin-bottom:10.0pt;
	margin-left:0cm;
	text-align:justify;
	text-justify:inter-ideograph;
	line-height:115%;
	layout-grid-mode:char;
	text-autospace:none;
	word-break:break-hangul;
	font-size:10.0pt;
	font-family:"맑은 고딕";}
p.MsoFooter, li.MsoFooter, div.MsoFooter
	{mso-style-link:"바닥글 Char";
	margin-top:0cm;
	margin-right:0cm;
	margin-bottom:10.0pt;
	margin-left:0cm;
	text-align:justify;
	text-justify:inter-ideograph;
	line-height:115%;
	layout-grid-mode:char;
	text-autospace:none;
	word-break:break-hangul;
	font-size:10.0pt;
	font-family:"맑은 고딕";}
span.Char
	{mso-style-name:"머리글 Char";
	mso-style-link:머리글;}
span.Char0
	{mso-style-name:"바닥글 Char";
	mso-style-link:바닥글;}
.MsoChpDefault
	{font-family:"맑은 고딕";}
.MsoPapDefault
	{margin-bottom:10.0pt;
	text-align:justify;
	text-justify:inter-ideograph;
	line-height:115%;}
 /* Page Definitions */
 @page WordSection1
	{size:595.3pt 841.9pt;
	margin:3.0cm 72.0pt 72.0pt 72.0pt;}
div.WordSection1
	{page:WordSection1;}
-->
</style>

</head>

<body lang=KO link=blue vlink=purple style="margin:0; padding:0">

<div class=WordSection1>

<table class=MsoTableGrid border=0 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr>
  <td width=615 style='width:461.2pt;background:#4F81BD;padding:0cm 5.4pt 0cm 5.4pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:18.0pt'><b><span style='font-size:14.0pt;
  color:white'>스마트홈<span lang=EN-US>M </span>메인메뉴</span></b></p>
  </td>
 </tr>
</table>

<table class=MsoTableGrid border=1 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:4.0pt'></tr>
</table>

<table class=MsoTableGrid border=1 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:27.6pt'>
  <td width=154 style='width:115.3pt;border:solid white 1.5pt;border-right:
  none;background:#FABF8F;padding:0cm 5.4pt 0cm 5.4pt;height:27.6pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b><span style='font-size:14.0pt;
  color:#984806'>온도</span></b></p>
  </td>
  <td width=118 style='width:88.55pt;border:none;border-bottom:solid #FBD4B4 1.5pt;
  padding:0cm 5.4pt 0cm 5.4pt;height:27.6pt'>
  <p class=MsoNormal align=left style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:left;line-height:normal'><b><span lang=EN-US style='font-size:
  16.0pt'><?=$device_data[0] ?></span></b><b><span style='font-size:16.0pt'>도</span></b></p>
  </td>
  <td width=217 style='width:163.05pt;border:solid white 1.5pt;border-left:
  none;background:#E5B8B7;padding:0cm 5.4pt 0cm 5.4pt;height:27.6pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b><span style='font-size:14.0pt;
  color:#943634'>조도밝기</span></b></p>
  </td>
  <td width=126 style='width:94.3pt;border-top:solid white 1.5pt;border-left:
  none;border-bottom:solid #D99594 1.5pt;border-right:solid white 1.5pt;
  padding:0cm 5.4pt 0cm 5.4pt;height:27.6pt'>
  <p class=MsoNormal align=left style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:left;line-height:normal'><b><span lang=EN-US style='font-size:
  16.0pt'><?=$device_data[1] ?>%</span></b></p>
  </td>
 </tr>
 <tr style='height:27.25pt'>
  <td width=154 style='width:115.3pt;border:solid white 1.5pt;border-top:none;
  background:#FABF8F;padding:0cm 5.4pt 0cm 5.4pt;height:27.25pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b><span style='font-size:14.0pt;
  color:#984806'>습도</span></b></p>
  </td>
  <td width=118 style='width:88.55pt;border-top:none;border-left:none;
  border-bottom:solid #FABF8F 1.5pt;border-right:solid white 1.5pt;padding:
  0cm 5.4pt 0cm 5.4pt;height:27.25pt'>
  <p class=MsoNormal align=left style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:left;line-height:normal'><b><span lang=EN-US style='font-size:
  16.0pt'><?=$device_data[2] ?>%</span></b></p>
  </td>
  <td width=217 style='width:163.05pt;border-top:none;border-left:none;
  border-bottom:solid white 1.5pt;border-right:solid white 1.5pt;background:
  #E5B8B7;padding:0cm 5.4pt 0cm 5.4pt;height:27.25pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b><span style='font-size:14.0pt;
  color:#943634'>가스</span></b></p>
  </td>
  <td width=126 style='width:94.3pt;border-top:none;border-left:none;
  border-bottom:solid #D99594 1.5pt;border-right:solid white 1.5pt;padding:
  0cm 5.4pt 0cm 5.4pt;height:27.25pt'>
  <p class=MsoNormal align=left style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:left;line-height:normal'><b><span lang=EN-US style='font-size:
  16.0pt'><?=$device_data[3] ?>%</span></b></p>
  </td>
 </tr>
</table>

<table class=MsoTableGrid border=1 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:4.0pt'></tr>
</table>

<table class=MsoTableGrid border=1 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:42.5pt'>
  <td width=205 style='width:153.7pt;border:solid white 3.0pt;background:<?=$bgv[1] ?>;
  padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=1&run=<?=$dsw[1] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[1] ?>;'>조명</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border:solid white 3.0pt;border-left:
  none;background:<?=$bgv[2] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=2&run=<?=$dsw[2] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[2] ?>;'>에어컨</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border:solid white 3.0pt;border-left:
  none;background:<?=$bgv[3] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=3&run=<?=$dsw[3] ?>'>
          <span style='font-size:14.0pt;color:<?=$fgv[3] ?>;'>보일러</span></a>
    </b></p>
  </td>
 </tr>
 <tr style='height:42.5pt'>
  <td width=205 style='width:153.7pt;border:solid white 3.0pt;border-top:none;
  background:<?=$bgv[4] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=4&run=<?=$dsw[4] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[4] ?>;'>제습기</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[5] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=5&run=<?=$dsw[5] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[5] ?>;'>가습기</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[6] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=6&run=<?=$dsw[6] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[6] ?>;'>공기환풍</span></a>
      </b></p>
  </td>
 </tr>
 <tr style='height:42.5pt'>
  <td width=205 style='width:153.7pt;border:solid white 3.0pt;border-top:none;
  background:<?=$bgv[7] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=7&run=<?=$dsw[7] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[7] ?>;'>소화부저</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[8] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=8&run=<?=$dsw[8] ?>'>
      <span lang=EN-US style='font-size:14.0pt;color:<?=$fgv[8] ?>;'>TV</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[0] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=0&run=<?=$dsw[0] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[0] ?>;'>전체LED</span></a>
      </b></p>
  </td>
 </tr>
 <tr style='height:42.5pt'>
  <td width=205 style='width:153.7pt;border:solid white 3.0pt;border-top:none;
  background:<?=$bgv[9] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=9&run=<?=$dsw[9] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[9] ?>;'>모터회전</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[11] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=11&run=<?=$dsw[11] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[11] ?>;'>스위치1</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[12] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=12&run=<?=$dsw[12] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[12] ?>;'>스위치2</span></a>
      </b></p>
  </td>
 </tr>
 <tr style='height:42.5pt'>
  <td width=205 style='width:153.7pt;border:solid white 3.0pt;border-top:none;
  background:<?=$bgv[13] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=13&run=<?=$dsw[13] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[13] ?>;'>스위치3</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[14] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=14&run=<?=$dsw[14] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[14] ?>;'>스위치4</span></a>
      </b></p>
  </td>
  <td width=205 style='width:153.75pt;border-top:none;border-left:none;
  border-bottom:solid white 3.0pt;border-right:solid white 3.0pt;background:
  <?=$bgv[10] ?>;padding:0cm 5.4pt 0cm 5.4pt;height:42.5pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b>
      <a href='./device_run.php?device=10&run=<?=$dsw[10] ?>'>
      <span style='font-size:14.0pt;color:<?=$fgv[10] ?>;'>스위치A</span></a>
      </b></p>
  </td>
 </tr>
</table>

<table class=MsoTableGrid border=1 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:4.0pt'></tr>
</table>

<table class=MsoTableGrid border=0 cellspacing=0 cellpadding=0
 style='border-collapse:collapse;border:none'>
 <tr style='height:20.0pt'>
  <td width=615 style='width:461.2pt;background:#4F81BD;padding:0cm 5.4pt 0cm 5.4pt'>
  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;
  text-align:center;line-height:normal'><b><span style='font-size:12.0pt;
  color:white'>커널연구회<span lang=EN-US>(<a href=http://www.kernel.bz>www.kernel.bz</a>)
  </span></span></b></p>
  </td>
 </tr>
</table>

</div>

</body>

</html>

<?php

MysqlClose2($dbLink);

?>

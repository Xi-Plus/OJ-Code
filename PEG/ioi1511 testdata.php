<?php
$N=1000;
$K=1;
$L=1000000000;
echo $N." ".$K." ".$L."\n";
$arr=array();
$l=array();
$l2=array();
$r=array();
$r2=array();
for ($i=0; $i < $N; $i++) { 
	$t=rand(0,$L-1);
	$arr[]=$t;
	if ($t<$L/2) {
		$l[]=$t;
	}else {
		$r[]=$L-$t;
	}
}
sort($arr);
foreach ($arr as $key => $val) {
	echo $val." ";
}
echo "\n";
echo "\n";
sort($l);
sort($r);
foreach ($l as $key => $val) {
	echo $val." ";
	$l2[$key]=$l2[$key-$K]+$val;
}
echo "\n";
foreach ($l2 as $key => $val) {
	echo $val." ";
}
echo "\n";
foreach ($r as $key => $val) {
	echo $val." ";
	$r2[$key]=$r2[$key-$K]+$val;
}
echo "\n";
foreach ($r2 as $key => $val) {
	echo $val." ";
}
echo "\n";
?>
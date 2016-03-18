<?php
$N=1000;
$K=1;
$L=1000000000;
echo $N." ".$K." ".$L."\n";
$arr=array();
for ($i=0; $i < $N; $i++) { 
	$t=rand(0,$L-1);
	$arr[]=$t;
}
sort($arr);
foreach ($arr as $key => $val) {
	echo $val." ";
}
echo "\n";
?>
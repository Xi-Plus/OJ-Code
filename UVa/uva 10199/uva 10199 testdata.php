<?php
function RandomString($len){
    $characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    $randstring = "";
    for ($i = 0; $i < $len; $i++) {
        $randstring .= $characters[rand(0, strlen($characters))];
    }
    return $randstring;
}
$n=10;
echo $n."\n";
$name=array();
for ($i=1; $i <= $n; $i++) { 
	$name[$i]=RandomString(20);
	echo $name[$i]."\n";
}
$k=20;
$ship=array();
for ($i=0; $i < $k; $i++) { 
	$a=0;$b=0;
	while($a==$b){
		$a=rand(1,$n);
		$b=rand(1,$n);
	}
	$ship[$a][$b]=true;
}
echo count($ship,COUNT_RECURSIVE)-count($ship)."\n";
foreach ($ship as $key1 => $temp1) {
	foreach ($temp1 as $key2 => $temp2) {
		echo $name[$key1]." ".$name[$key2]."\n";
	}
}
echo "0\n";
?>
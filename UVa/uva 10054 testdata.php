<?php
$t=5;
echo $t."\n";
while ($t--) {
	$n=10;
	echo $n."\n";
	$k=rand(1,10);
	echo $k;
	$n--;
	while ($n--) {
		$m=rand(1,10);
		echo " ".$m."\n".$m;
	}
	echo " ".$k."\n";
}
?>
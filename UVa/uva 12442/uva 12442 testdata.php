<?php
$n=100;
echo "1\n";
echo $n."\n";
for ($i=1; $i <= $n; $i++) { 
	echo $i." ".rand(1,$n)."\n";
}
?>
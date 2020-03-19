<?php
	$n = trim(fgets(STDIN));
	$ans=1;
	while($n){
		$ans*=$n;
		while($ans%10==0)$ans/=10;
		$ans%=1000000000000;
		$n--;
	}
	echo $ans%1000000000;
?>

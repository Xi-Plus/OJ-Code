process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (n) {
    var s="";
    while(n--) s+="Ann";
    console.log(s);
});
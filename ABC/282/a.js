const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question('', k => {
    k = parseInt(k);
    let result = '';
    for (let i = 0; i < k; ++i) {
        result += String.fromCharCode('A'.charCodeAt(0) + i);
    }
    console.log(result);
    readline.close();
});

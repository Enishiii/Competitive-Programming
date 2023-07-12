const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question('', n => {
    for (let i = n; i >= 0; --i) {
        console.log(i);
    }
    readline.close();
});

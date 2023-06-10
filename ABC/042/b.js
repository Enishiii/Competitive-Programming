const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
rl.on('line', function(line) {
    input.push(line);
}).on('close', function() {
    const [num_strings, length_strings] = input[0].split(' ').map(Number);
    const strings = input.slice(1);

    strings.sort();

    console.log(strings.join(''));

    process.exit(0);
});

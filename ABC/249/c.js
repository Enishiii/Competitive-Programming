const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [n, k] = input[0].split(' ').map(Number);
    const strings = input.slice(1, n + 1);

    let maxOccurrence = 0;
    for (let bit = 0; bit < (1 << n); ++bit) {
        const charCount = new Array(26).fill(0);
        for (let idx = 0; idx < n; ++idx) {
            if ((bit >> idx) & 1) {
                for (let char of strings[idx]) {
                    charCount[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
                }
            }
        }
        let currentOccurrence = charCount.filter(count => count === k).length;
        maxOccurrence = Math.max(maxOccurrence, currentOccurrence);
    }
    console.log(maxOccurrence);
});

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [n, m] = input[0].split(' ').map(Number);
    let s = input.slice(1, n + 1);

    let ans = 0;

    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            let ok = true;
            for (let k = 0; k < m; ++k) {
                if (s[i][k] == 'x' && s[j][k] == 'x') ok = false;
            }
            if (ok) ans++;
        }
    }
    console.log(ans);

    process.exit(0);
});

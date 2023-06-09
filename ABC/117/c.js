const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [numPieces, numTargets] = input[0].split(' ').map(Number);
    let targets = input[1].split(' ').map(Number);
    targets.sort((a, b) => a - b);

    let distances = [];
    for (let i = 0; i < numTargets - 1; ++i) {
        distances[i] = targets[i + 1] - targets[i];
    }

    distances.sort((a, b) => a - b);

    let minMoves = 0;
    for (let i = 0; i < numTargets - numPieces; ++i) {
        minMoves += distances[i];
    }

    console.log(minMoves);
});

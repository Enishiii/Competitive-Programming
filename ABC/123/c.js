const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs.push(Number(line));
    if (inputs.length === 6) {
        calculateMinTravelTime(inputs);
        rl.close();
    }
});

function calculateMinTravelTime(inputs) {
    const n = inputs[0];
    const capacities = inputs.slice(1);
    const minTravelTime = Math.max(...capacities.map(capacity => Math.floor((n-1)/capacity))) + 5;
    console.log(minTravelTime);
}

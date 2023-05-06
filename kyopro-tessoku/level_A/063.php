<?php

function bfs($graph, $num_node)
{
    $distances = array_fill(0, $num_node, -1);
    $bfs_queue = new SplQueue();
    $distances[0] = 0;
    $bfs_queue->enqueue(0);

    while(!$bfs_queue->isEmpty()) {
        $current_node = $bfs_queue->dequeue();

        foreach($graph[$current_node] as $neighbor) {
            if ($distances[$neighbor] === -1) {
                $distances[$neighbor] = $distances[$current_node] + 1;
                $bfs_queue->enqueue($neighbor);
            }
        }
    }

    return $distances;
}

// 入力を受け取る
fscanf(STDIN, "%d %d", $num_node, $num_edges);
$graph = array();
for ($i = 0; $i < $num_node; ++$i) {
    $graph[$i] = array();
}

for ($i = 0; $i < $num_edges; ++$i) {
    fscanf(STDIN, "%d %d", $node_a, $node_b);
    $node_a--;
    $node_b--;
    $graph[$node_a][] = $node_b;
    $graph[$node_b][] = $node_a;
}

// BFSで距離を計算
$distances = bfs($graph, $num_node);

// 答えを出力
foreach($distances as $distance) {
    echo $distance . PHP_EOL;
}

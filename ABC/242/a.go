/* 問題文
あるプログラミングコンテストでは、以下のルールに従って参加者に T シャツをプレゼントします。
上位A 位までの参加者は、必ず T シャツが貰える。
加えて、上位A+1 位からB 位までの参加者のうちC 人が一様ランダムに選ばれ、選ばれた参加者は T シャツを貰える。
コンテストには1000 人が参加し、全ての参加者が相異なる順位を取りました。
このコンテストの参加者であるいろはちゃんは、X 位を取りました。
このとき、いろはちゃんが T シャツを貰える確率を求めてください。

制約
入力はすべて整数
1≤A<B≤1000
1≤C≤B−A
1≤X≤1000 */

package main

import (
	"fmt"
)

func main() {
	var a, b, c, x int
	fmt.Scan(&a, &b, &c, &x)

	if x <= a {
		fmt.Printf("%.10f\n", 1.0)
	} else if x <= b {
		res := float64(c) / float64(b-a)
		fmt.Printf("%.10f\n", res)
	} else {
		fmt.Printf("%.10f\n", 0.0)
	}
}

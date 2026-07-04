package palindromenumber

// import "strconv"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	if x != 0 && x%10 == 0 {
		return false
	}

	reversed := 0
	for x > reversed {
		reversed = reversed*10 + x%10
		x /= 10
	}

	return x == reversed || x == reversed/10
	// s := strconv.Itoa(x)

	// left := 0
	// right := len(s) - 1

	// for left < right {
	// 	if s[left] != s[right] {
	// 		return false
	// 	}

	// 	left++
	// 	right--
	// }

	// return true
}

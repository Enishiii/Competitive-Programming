package palindromenumber

import "testing"

func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		name string
		x    int
		want bool
	}{
		{
			name: "positive palindrome",
			x:    121,
			want: true,
		},
		{
			name: "negative number",
			x:    -121,
			want: false,
		},
		{
			name: "trailing zero",
			x:    10,
			want: false,
		},
		{
			name: "zero",
			x:    0,
			want: true,
		},
		{
			name: "even digits palindrome",
			x:    1221,
			want: true,
		},
		{
			name: "single digit",
			x:    7,
			want: true,
		},
		{
			name: "not palindrome",
			x:    123,
			want: false,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isPalindrome(tt.x)

			if got != tt.want {
				t.Errorf("isPalindrome(%d) = %v, want %v", tt.x, got, tt.want)
			}
		})
	}
}

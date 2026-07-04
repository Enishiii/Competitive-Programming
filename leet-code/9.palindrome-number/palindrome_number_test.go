package palindromenumber

import "testing"

func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		name string
		x int
		want bool
	}{
		{
			name: "positive palindrome",
			x: 121,
			want: true,
		},
		{
			name: "negative number",
			x: -121,
			want: false,
		},
		{
			name: "trailing zero",
			x: 10,
			want: false,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T)  {
			got := isPalindrome(tt.x)

			if got != tt.want {
				t.Errorf("isPalindrome(%d) = %v, want %v", tt.x, got, tt.want)
			}
		})
	}
}

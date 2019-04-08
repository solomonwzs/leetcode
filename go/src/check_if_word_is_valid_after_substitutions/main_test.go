/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-08
 * @license MIT
 */

package check_if_word_is_valid_after_substitutions

import "testing"

func TestIs(t *testing.T) {
	t.Log(isValid("aabcbc") == true)
}

func TestIs1(t *testing.T) {
	t.Log(isValid("abcabcababcc") == true)
}

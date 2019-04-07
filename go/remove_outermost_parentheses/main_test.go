/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-04-07
 * @license MIT
 */

package main

import "testing"

func TestRemove(t *testing.T) {
	t.Log(removeOuterParentheses("(()())(())"))
}

func TestFunction1(t *testing.T) {
	t.Log(removeOuterParentheses("(()())(())(()(()))"))
}

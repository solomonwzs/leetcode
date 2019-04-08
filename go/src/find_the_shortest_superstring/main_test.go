/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-06
 * @license MIT
 */

package main

import "testing"

func TestShort(t *testing.T) {
	t.Log(shortestSuperstring([]string{"aab", "abc"}))
}

func TestShort1(t *testing.T) {
	t.Log(shortestSuperstring([]string{"catg", "ctaagt", "gcta",
		"ttca", "atgcatc"}))
}

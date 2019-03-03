/**
 * @author  Solomon Ng <solomon.wzs@gmail.com>
 * @version 1.0
 * @date    2019-03-03
 * @license MIT
 */

package main

import "testing"

func TestCommon(t *testing.T) {
	t.Log(commonChars([]string{
		"bella", "label", "roller",
	}))
}

func TestCommon1(t *testing.T) {
	t.Log(commonChars([]string{
		"cool", "lock", "cook",
	}))
}

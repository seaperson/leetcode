package main

import (
	"fmt"
	"strings"
)

func main() {
	result := solveNQueens(3)
	fmt.Println(result)
}

func solveNQueens(n int) [][]string {
	if n == 0 {
		return nil
	}
	// 初始化
	bq := make([][]string, n)
	for i := range bq {
		bq[i] = make([]string, n)
		for j := range bq[i] {
			bq[i][j] = "."
		}
	}
	var res [][]string
	backTrack(bq, 0, &res)
	return res
}

func backTrack(board [][]string, row int, res *[][]string) {
	// 终止条件:所有行都遍历完了
	if row == len(board) {
		t := make([]string, len(board))
		for i := 0; i < len(board); i++ {
			t[i] = strings.Join(board[i], "")
		}
		*res = append(*res, t)
		return
	}
	n := len(board)
	// 遍历所有列,找出每一列的可能性
	for col := 0; col < n; col++ {
		if !isValid(board, row, col) {
			continue
		}
		// 选择
		board[row][col] = "Q"
		// 递归 下一行
		backTrack(board, row+1, res)
		// 撤销选择
		board[row][col] = "."
	}
}

// 因为是一行一行往下遍历,所有只需要往上判断
// 直上-同一列
// 左上-左斜线
// 右上-右斜线
func isValid(board [][]string, row, col int) bool {
	// 同一列
	for i := row; i >= 0; i-- {
		if board[i][col] == "Q" {
			return false
		}
	}
	// 右上角
	for i, j := row-1, col+1; i >= 0 && j < len(board); {
		if board[i][j] == "Q" {
			return false
		}
		i--
		j++
	}
	// 左上角
	for i, j := row-1, col-1; i >= 0 && j >= 0; {
		if board[i][j] == "Q" {
			return false
		}
		i--
		j--
	}
	return true
}

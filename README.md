# Push Swap

puseudo code

1. スタックaとスタックbを宣言する

2. inputデータをエラーハンドリングする
	この時に、文字列で数値が与えられていても、split関数で処理する

3. スタックaを初期化し、循環連結リストに格納する
	この時にオーバーフローやダブり、シンタックスエラーを処理する

4. もしもスタックaがソートされていなかった場合に、ソートを開始する
	Check for 2 numbers -> if so, simply swap the numbers.

	Check for 3 numbers -> if so, tiny sort

	Check if the stack has more than 3 numbers
	-> Turk Algorithm


#### テストケース

```
make all && make bonus && chmod +x test.sh && ./test.sh

```

### 視覚化

```
make all && make bonus && chmod +x visual.sh && ./visual.sh

```


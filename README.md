# UEFI Basic

A simple BASIC language intepreter that runs on UEFI. Feel free to submit a pull request.

これは、UEFI BOOTする、64bit整数版 TinyBASICインタープリターです。

オリジナル版は、68000 Tiny BASIC です。


## オリジナル Git Repository からの大きな変更点

・UEFI BOOT と 64bit Linux gcc (CUI) 以外の動作環境の切り捨て

・予約語を普通の文字列型に変更

・整数のビット数を16bitから64bitに変更

・多少の Refactoring を実施

・【重要】コンパイラをMingw-w64-gcc から、Ubuntu24.04上の 普通のgcc-13 に変更しました
          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## 環境構築メモ

(1)・Lubuntu24.04 を用意（普通のUbuntu24.04でも良い） QEMUを動かすので、GUIが必要。

(2)・QEMUを入れる。・・・UEFIブートを試すエミュレータ。

 ```
 # apt install qemu-system-x86
 ```

(3)・OVMFを入れる。・・・UEFIのBIOS（変な言い方だが、そう）というかファームウェアね。 Open Virtual Machine Firmware とかそんな感じの。

 ```
 # apt install ovmf
 ```

## QEMU上で動かす

 $ make run

・エラー発生時の行番号は、BASICの行ではなく、 basic.c のエラー発生時の行番号であることに注意

・変数は A-Zしか使用できない。

・文字列変数はない。

・整数は64bit

・配列は実装されない。

・Arduino等にあるような　SD Card File I/O や Port Pin Control など、は実装されない。

## QEMUの終了のさせ方
・[CTRL] ＋ [ALT] + [２] を押してQEMUコンソールに戻す
・>quit で終了


## 注意事項

・Linuxコマンドラインでは libcの関数が使用可能だが、UEFIビルドではリンクエラーするので注意。

## 実機で動くのか？

ちなみに、てきとーなUSBメモリーをFAT32フォーマットして、

USBドライブ名: /EFI/BOOT/BOOTX64.EFI

のようにさっきのファイルを配置して、

C:ドライブだったSSDを抜いておいて起動すると、ちゃんとBASICが起動する。


だけど、メーカーロゴが残ったままだし、全画面じゃないし（中央部分にしかコンソールがprintしない）不満が・・・


## 感想：ひとりごと

うーん、なんだろう。PIC32MXでBASIC動かしたときもそうだったんだけど。
まともなBASICインタプリタって、どっかに置いてくれないですかね。
バグバグやん。


こいつ、files とか loadとかsaveがない。なんも出来ん。

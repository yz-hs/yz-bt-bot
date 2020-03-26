# todo-list

- [ ] 运行代码的字符编码问题，导致 无法/错误 输入输出数据。

- [ ] 可以将类似的命令合并,某一类功能项目包含有关功能。


- [ ] 加入复读功能。


- [ ] 将命令前缀符由`#`改为`$`或其他符号。


- [ ] 对单独命令应有单独的 help，参数为`-help`。


- [ ] 对运行代码功能加入沙盒，否则太危险。要么就直接取消运行代码功能。


- [ ] 将 bot 的运行端转移到另一个电脑。


- [ ] 改版help界面与内容，使之更美观、详细。


- [ ] 对读入命令与命令的处理要严谨化。考虑使用检测是否包含字符串的形式。

- [ ] 加入套娃机制：

  - 这样发消息可以触发套娃（ABC表示不重字且长度超过1的句子，同种字母表示同一个字）

    ``` 
    ABCABC
    ABC:ABC
    ABC"ABC"
    ```

  - 例子：
    
    禁止禁止套娃  —>  禁止禁止禁止套娃
    
禁止禁止套娃套娃  —> 禁止禁止禁止套娃套娃套娃
    
    建议改为："建议改为"  —> 建议改为："建议改为:"建议改为""
    
  - 支持符号：' " : ：？?


- [ ] 加入特定词语识别，当消息中出现某段话，进行相应的输出/动作（作为彩蛋）。如，

  - `!sleep` 禁言自己 8h 。
  
  - `I AK IOI` 自动膜拜。
  
  - `嘤嘤嘤` 卖萌。
# 配置自己的WSL

## 更换为阿里云源

#### 先备份

```shell
sudo cp /etc/apt/source.list /etc/apt/source.list.back  
```

#### 然后

```shell
sudo vim /etc/apt/source.list
```

#### 更换文件内容为

```
deb http://mirrors.aliyun.com/ubuntu/ focal main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal universe
deb http://mirrors.aliyun.com/ubuntu/ focal-updates universe
deb http://mirrors.aliyun.com/ubuntu/ focal multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-updates multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal-security universe
deb http://mirrors.aliyun.com/ubuntu/ focal-security multiverse
```

#### 更新一下
```shell
sudo apt-get update
```

## 安装及配置zsh

#### 安装zsh

```shell
sudo apt-get install zsh
```

#### 更改默认shell为zsh(不用sudo，需要输入密码)

```shell
chsh -s /bin/zsh
```

#### 安装oh-my-zsh

```shell
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

#### 更改主题
  
```shell
git clone --depth=1 https://gitee.com/romkatv/powerlevel10k.git ~/powerlevel10k

echo 'source ~/powerlevel10k/powerlevel10k.zsh-theme' >>! ~/.zshrc

git clone --depth=1 https://gitee.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/themes/powerlevel10k
```

然后在`.zshrc`中设置`ZSH_THEME="powerlevel10k/powerlevel10k"`

#### 字体更改

前往 https://github.com/romkatv/powerlevel10k#Fonts 下载 `MesloLGS NF` 字体

打开 `windows terminal` 设置，在 `profiles-defaults` 中添加：
```json
"fontFace": "MesloLGS NF"
```

#### 最后一步
  
```shell
source .zshrc
```

## 安装插件

#### autojump

```shell
sudo apt-get install autojump
```

添加一行到 `.zshrc` 的最后面

```shell
. /usr/share/autojump/autojump.sh
```

然后 ```source .zshrc``` 即可

#### zsh-syntax-highlighting 语法高亮插件

```shell
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git

echo "source ${(q-)PWD}/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ${ZDOTDIR:-$HOME}/.zshrc

source .zshrc
```

#### zsh-autosuggestions 语法历史记录插件

```shell
git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
```

然后 `vim .zshrc` 添加如下语句

```
plugins=(zsh-autosuggestions)

source $ZSH_CUSTOM/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
```

最后 `source .zshrc`

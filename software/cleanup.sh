#!/bin/bash

# 清理 apt 缓存和多余的包
echo "清理 APT 缓存和多余的包..."
sudo apt-get clean
sudo apt-get autoremove
sudo apt-get autoclean

# 清理用户缓存文件
echo "清理用户缓存文件..."
sudo rm -rf ~/.cache/*

# 清理系统日志（删除一天前的日志）
echo "清理系统日志..."
sudo journalctl --vacuum-time=1d

# 删除 /home/pi/Downloads 里的所有文件（如果你需要备份，可以先手动复制）
echo "清理 /home/pi/Downloads..."
sudo rm -rf /home/pi/Downloads/*

# 删除 /home/pi/.cache 里的所有文件
echo "清理 /home/pi/.cache..."
sudo rm -rf /home/pi/.cache/*

# 删除编译生成的文件（根据你的项目调整）
echo "清理项目编译文件..."
cd ~/ZWL-WBC/GebotMini/software
find . -name "*.o" -exec rm -f {} \;
find . -name "__pycache__" -exec rm -rf {} \;

# 显示清理后磁盘空间
echo "清理完成，当前磁盘空间："
df -h


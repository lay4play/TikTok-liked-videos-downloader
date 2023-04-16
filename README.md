# TikTok-liked-videos-downloader
A simple script to download TikTok liked/saved videos.

# Instructions
**The script need a *page.html* file**, which you can obtain going in the liked/saved videos page, **scrolling all the way down to the bottom and pressing ctrl+s to save the page.**
The browser will download an .html file, **you need to rename it in *page.html* and put it in the same directory of the script.** After that you can execute the script and wait until it finishes downloading the videos.

# Compilation
The code can be compiled using gcc/g++, in order to get the code working **make sure that yt-dlp is installed on your system.**

# Addition information
* **This script is currently only Linux-compatible**, i haven't tested it on any Windows computer, but probably i will try to make a Windows-capable version of it.
* The script download the video from the recent ones to the past ones.
* yt-dlp uses the TikTok video description as filename, which can create problem with videos that has a huge description resulting in a lot of error for *Filename too long*. **This script simply rename every video with a number in descending order.**
* I made this code because I needed to practice for my IT test, so this might not be the best way to do this nor the most correct way to do it.
# Known bugs
* **The script download only the audio of slideshow videos**: this seem to be an issue with yt-dlp.




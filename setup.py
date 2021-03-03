import shutil
import urllib.request
import json
import os

# Configurations
delete_source_file = True

# SELECT YOUR PLATFORM
# 2 - linux_amd64
# 3 - linux_i386
# 6 - win32_mingw-w64
# 8 - win64_mingw-w64
platform = 8

# End of configurations

# Gets the necessary links in the raylib repo
latest_release_url = "https://api.github.com/repos/raysan5/raylib/releases/latest"
latest_release_json = json.load(urllib.request.urlopen(latest_release_url))
asset_download_link = latest_release_json["assets"][platform]["browser_download_url"]
asset_file_name = asset_download_link.replace(
    "https://github.com/raysan5/raylib/releases/download/" + latest_release_json["tag_name"] + "/", "")

# Checks if already downloaded the file
if not os.path.exists(asset_file_name):
    # Downloads the file
    urllib.request.urlretrieve(asset_download_link, asset_file_name)
    print(asset_file_name + " downloaded!")
else:
    print(asset_file_name + " already downloaded!")

# Unpack the file
shutil.unpack_archive(asset_file_name)
print(asset_file_name + " extracted!")

if platform == 2 or platform == 3:  # Set extension for Linux
    folder_name = asset_file_name.replace(".tar.gz", "")
elif platform == 6 or platform == 8:  # Set extension for Windows
    folder_name = asset_file_name.replace(".zip", "")

if os.path.exists("./include"):
    shutil.rmtree("./include")
if os.path.exists("./lib"):
    shutil.rmtree("./lib")

# Moving the extracted files to the project folder
shutil.move("./" + folder_name + "/include", "./include")
shutil.move("./" + folder_name + "/lib", "./")
os.rmdir("./" + folder_name)
print("raylib files moved with success!")

urllib.request.urlretrieve("https://raw.githubusercontent.com/raysan5/raylib/master/src/rlgl.h", "./include/rlgl.h")
urllib.request.urlretrieve("https://raw.githubusercontent.com/raysan5/raygui/master/src/raygui.h", "./include/raygui.h")
urllib.request.urlretrieve("https://raw.githubusercontent.com/raysan5/raylib/master/src/raymath.h", "./include"
                                                                                                    "/raymath.h")

# Deletes the precompiled binaries from github
if delete_source_file:
    os.remove("./" + asset_file_name)


print("Finished!!!")

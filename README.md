# ***Sliding Puzzle***
## **Introduction**
+ Bài tập lớn - Sliding Puzzle (INT2215 1 - Lập trình nâng cao)

+ Mã sinh viên:  21020286 - Lê Minh Châu - K66CB - UET

## **Description**


### *Game description and rule*

- Đây là trò chơi xếp hình trong khung 4x4 với 15 ô ảnh bị xáo trộn. Nhiệm vụ của bạn là sắp xếp những ô ảnh về đúng thứ tự bằng cách di chuyển phím lên trên, xuống dưới, trái, phải.

- Game gồm 3 chủ đề hình ảnh với background tương ứng để bạn tuỳ ý lựa chọn.

### *Controls and Options*

| Control | Key   |
|---------|-------|
| UP      | ↑     |
| DOWN    | ↓     |
| LEFT    | ←     |
| RIGHT   | →     |

| Option         | Key       |
|----------      |-----------|
| Shuffle Puzzle | x |
| Return to home | b |


### *Preview*


![](image/FirstPic.png)

![](image/About.png)

![](image/ThemeChoice.png)

![](image/123.png)



## **Setup**

- *Cài đặt*
  1. Truy cập vào đường link:  https://drive.google.com/drive/folders/1JbpsFMJpLObLW2v72GuEu6sFVJ3vcx0H?usp=sharing
  
  2. Vào file **"Release"**, tải lần lượt từng file **"Setup.exe"** và **"Chou_puzzle.msi"** (lưu ý 2 file vừa tải về để trong cùng 1 thư mục máy tính)

  3. Vào file **"Setup.exe"**, Sau đó cài đặt theo hướng dẫn của chương trình.

  4. Nhấn close, thoát ra màn hình chính, ấn đúp chuột vào icon puzzle để bắt đầu chơi.

- *Gỡ bỏ*
  1. Vào control panel.

  2. Tìm kiếm Uninstall a program.

  3. Ấn đúp chuột vào file SlidingPuzzle_21020286UET.

  4. Ấn "Yes" nếu chắc chắn bạn muốn gỡ bỏ chương trình.

- *Trong trường hợp xuất hiện lỗi "The code execution cannot proceed because ....dll was not found. Reinstalling the program may fix this problem.":*

  1. Truy cập vào đường link ở trên, tải về file **"System32"** và **"SysWOW64"**.

  2. Giải nén file vừa tải về.

  3. Copy file .dll  trong file **"System32"** dán vào trong thư mục **"C:\Windows\System32"** .

  4. Copy file .dll  trong file **"SysWOW64"** dán vào trong thư mục **"C:\Windows\SysWOW64"**.

  5. Thoát ra ngoài và chạy lại chương trình.


- *Mọi khó khăn trong việc cài đặt, trong quá trình chơi, hay gỡ bỏ, hãy email qua 21020286@vnu.edu.vn.*



## **See also**
### *Các kĩ thuật sử dụng*


- Thư viện SDL2.0.

- Tạo các đối tượng: các ô ảnh, ...

- Tạo các đối tượng phụ: số lượt di chuyển...

- Tạo các menu: Bắt đầu, kết thúc, lựa chọn chủ đề, hướng dẫn,...

- Đóng gói chương trình để có thể cài đặt, chơi được ở các máy tính thông thường.

### *Nguồn tham khảo:*
- https://lazyfoo.net/tutorials/SDL/index.php (các hàm trong thư viện SDL2.0, ...)

- https://phattrienphanmem123az.com/lap-trinh-game-cpp (tile map, tạo menu).
- Một số hình ảnh tự design và âm thanh tìm ở trên web -.-
https://www.wavsource.com/sfx/sfx.htm,
https://vi.pngtree.com/
- Logic game em tự nghĩ.
### *Mức điểm tự đánh giá: 9/10.*

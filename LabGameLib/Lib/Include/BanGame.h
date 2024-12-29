#ifdef GAMEENGINE_API_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)  // Export to create DLL
#else
#define MYLIBRARY_API __declspec(dllimport)  // Import to use DLL
#endif

#ifndef BANGAME_H
#define BANGAME_H
#include <memory.h>
#include <functional>
#include <d3d11.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <string>
#include <vector>
#include <format>
#include <nlohmann/json.hpp>

#include "DataFormat.h"


namespace BanZ
{
#ifndef SUPPORT_ENUM_NAME
#define SUPPORT_ENUM_NAME
    namespace KeyBoard {
        enum Keys : unsigned char
        {
            None = 0,

            Back = 0x8,
            Tab = 0x9,

            Enter = 0xd,

            Pause = 0x13,
            CapsLock = 0x14,
            Kana = 0x15,
            ImeOn = 0x16,

            Kanji = 0x19,

            ImeOff = 0x1a,
            EscapeKey = 0x1b,
            ImeConvert = 0x1c,
            ImeNoConvert = 0x1d,

            Space = 0x20,
            PageUp = 0x21,
            PageDown = 0x22,
            End = 0x23,
            Home = 0x24,
            Left = 0x25,
            Up = 0x26,
            Right = 0x27,
            Down = 0x28,
            Select = 0x29,
            Print = 0x2a,
            Execute = 0x2b,
            PrintScreen = 0x2c,
            Insert = 0x2d,
            Delete = 0x2e,
            Help = 0x2f,
            D0 = 0x30,
            D1 = 0x31,
            D2 = 0x32,
            D3 = 0x33,
            D4 = 0x34,
            D5 = 0x35,
            D6 = 0x36,
            D7 = 0x37,
            D8 = 0x38,
            D9 = 0x39,

            A = 0x41,
            B = 0x42,
            C = 0x43,
            D = 0x44,
            E = 0x45,
            F = 0x46,
            G = 0x47,
            H = 0x48,
            I = 0x49,
            J = 0x4a,
            K = 0x4b,
            L = 0x4c,
            M = 0x4d,
            N = 0x4e,
            O = 0x4f,
            P = 0x50,
            Q = 0x51,
            R = 0x52,
            S = 0x53,
            T = 0x54,
            U = 0x55,
            V = 0x56,
            W = 0x57,
            X = 0x58,
            Y = 0x59,
            Z = 0x5a,
            LeftWindows = 0x5b,
            RightWindows = 0x5c,
            Apps = 0x5d,

            SleepKey = 0x5f,
            NumPad0 = 0x60,
            NumPad1 = 0x61,
            NumPad2 = 0x62,
            NumPad3 = 0x63,
            NumPad4 = 0x64,
            NumPad5 = 0x65,
            NumPad6 = 0x66,
            NumPad7 = 0x67,
            NumPad8 = 0x68,
            NumPad9 = 0x69,
            Multiply = 0x6a,
            Add = 0x6b,
            Separator = 0x6c,
            SubtractKey = 0x6d,

            Decimal = 0x6e,
            Divide = 0x6f,
            F1 = 0x70,
            F2 = 0x71,
            F3 = 0x72,
            F4 = 0x73,
            F5 = 0x74,
            F6 = 0x75,
            F7 = 0x76,
            F8 = 0x77,
            F9 = 0x78,
            F10 = 0x79,
            F11 = 0x7a,
            F12 = 0x7b,
            F13 = 0x7c,
            F14 = 0x7d,
            F15 = 0x7e,
            F16 = 0x7f,
            F17 = 0x80,
            F18 = 0x81,
            F19 = 0x82,
            F20 = 0x83,
            F21 = 0x84,
            F22 = 0x85,
            F23 = 0x86,
            F24 = 0x87,

            NumLock = 0x90,
            Scroll = 0x91,

            LeftShift = 0xa0,
            RightShift = 0xa1,
            LeftControl = 0xa2,
            RightControl = 0xa3,
            LeftAlt = 0xa4,
            RightAlt = 0xa5,
            BrowserBack = 0xa6,
            BrowserForward = 0xa7,
            BrowserRefresh = 0xa8,
            BrowserStop = 0xa9,
            BrowserSearch = 0xaa,
            BrowserFavorites = 0xab,
            BrowserHome = 0xac,
            VolumeMute = 0xad,
            VolumeDown = 0xae,
            VolumeUp = 0xaf,
            MediaNextTrack = 0xb0,
            MediaPreviousTrack = 0xb1,
            MediaStop = 0xb2,
            MediaPlayPause = 0xb3,
            LaunchMail = 0xb4,
            SelectMedia = 0xb5,
            LaunchApplication1 = 0xb6,
            LaunchApplication2 = 0xb7,

            OemSemicolon = 0xba,
            OemPlus = 0xbb,
            OemComma = 0xbc,
            OemMinus = 0xbd,
            OemPeriod = 0xbe,
            OemQuestion = 0xbf,
            OemTilde = 0xc0,

            OemOpenBrackets = 0xdb,
            OemPipe = 0xdc,
            OemCloseBrackets = 0xdd,
            OemQuotes = 0xde,
            Oem8 = 0xdf,

            OemBackslash = 0xe2,

            ProcessKey = 0xe5,

            OemCopy = 0xf2,
            OemAuto = 0xf3,
            OemEnlW = 0xf4,

            Attn = 0xf6,
            Crsel = 0xf7,
            Exsel = 0xf8,
            EraseEof = 0xf9,
            Play = 0xfa,
            Zoom = 0xfb,

            Pa1 = 0xfd,
            OemClear = 0xfe,
        };
    }

    enum Mouse : unsigned char
    {
        LeftMouse = 0x01,
        RightMouse = 0x02,
        MiddleMouse = 0x04,
    };
#endif
    enum CollisionType {
        NON_Collision,
        Cicrle_Collision,
        Square_Collision,
        Triangle_Collision,
        Rectangle_Collision,
    };

    enum class COLOR
    {
        DEFAULT,
        RED,
        BLUE,
        GREEN,
        WHITE,
        BLACK,
    };

    enum class NETWORKSTATUS
    {
        FAIL = -1,
        NOT_CONNECT,
        ON_CONNECTING,
        CONNECTED,
    };

    typedef SmartPointer pSprite;
    typedef SmartPointer pAnimator;
    typedef SmartPointer pAnimation;
    typedef UINT AudioHandle;
    typedef UINT CameraHandle;
    typedef UINT FontHandle;

    class MYLIBRARY_API BanGame
    {
    public:
        static BanGame* Get();

        void QuitGame();
        int GameRun(std::function<void()> sceneInit,
            std::function<void(const float&)> sceneUpdate,
            std::function<void()> sceneRender);
        int GameRun(std::function<void(const float&)> sceneUpdate);
        float GetElapsedTime();

        pSprite CreateTexture(const std::string& fileLocal);
        pAnimation CreateAnimation(const std::string& name, const std::vector<std::string>& listLoadSprites);
        pAnimator CreateAnimator();
        AudioHandle CreateMusic(const std::string& fileLocal);
        FontHandle CreateMyFont(const std::string& fileLocal, const bool& exportAtlas = false);

        void AddAnimationToAnimator(pAnimator, pAnimation);
        void SetAnimation(pAnimator animator, UINT animationNum, bool replay);
        void UpdateAnimation(pAnimator animator, const float& rate);
        void PlayMusic(AudioHandle handle, bool isLoop);
        /**
     * @brief Hiển thị cửa sổ trò chơi với trạng thái được chỉ định.
     *
     * @param nCmdShow Trạng thái hiển thị của cửa sổ.
     * @param windowName Tên cửa sổ.
     * @param windowClass Tên class cửa sổ.
     * @param windowSizeX Chiều rộng cửa sổ.
     * @param windowSizeY Chiều cao cửa sổ.
     * @return true nếu hiển thị cửa sổ thành công, false nếu có lỗi xảy ra.
     */
        bool CreateGameWindow(_In_ HINSTANCE hInstance, _In_ int nCmdShow, std::wstring windowName, std::wstring windowClass, UINT windowSizeX, UINT windowSizeY);

        static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

        /**
  * @brief Cài đặt màu nền cho cửa sổ
  *
  * @param color Mã màu (r,g,b,a) từ 0 -> 255.
  */
        void SetBackgroundColor(const VECTOR4& color);

        /**
 * @brief Cài đặt màu nền cho cửa sổ
 *
 * @param color Mã màu COLOR.
 */
        void SetBackgroundColor(COLOR color);

        /**
* @brief Vẽ Đoạn thẳng lên màn hình cửa sổ
*
* @param begin Vị trí bắt đầu.
* @param end Vị trí kết thúc.
* @param size Độ rộng của Đoạn thẳng.
* @param angle Góc xoay đoạn thẳng.
* @param color Mã màu (r,g,b,a) từ 0 -> 255.
* @param layer Vẽ ở lớp thứ mấy.
*/
        void DrawLine(const VECTOR3& begin, const VECTOR3& end, const float& size, const VECTOR3& angle, const VECTOR4& color, const UINT& layer = 0);
        /**
* @brief Vẽ Đoạn thẳng lên màn hình cửa sổ
*
* @param begin Vị trí bắt đầu.
* @param end Vị trí kết thúc.
* @param size Độ rộng của Đoạn thẳng.
* @param angle Góc xoay đoạn thẳng.
* @param color Mã màu COLOR.
* @param layer Vẽ ở lớp thứ mấy.
*/
        void DrawLine(const VECTOR3& begin, const VECTOR3& end, const float& size, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);


        /**
* @brief Vẽ Đoạn đường(line) lên màn hình cửa sổ
*
* @param listNode list các node vị trí của đoạn đường(line).
* @param size Độ rộng của đoạn đường(line).
* @param angle Góc xoay đoạn đường(line).
* @param color Mã màu COLOR.
* @param layer Vẽ ở lớp thứ mấy.
*/
        void DrawLine(const std::vector<VECTOR2>& listNode, const float& size, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);
        /**
* @brief Vẽ Đoạn đường(line) lên màn hình cửa sổ
*
* @param listNode list các node vị trí của đoạn đường(line).
* @param size Độ rộng của đoạn đường(line).
* @param angle Góc xoay đoạn đường(line).
* @param color Mã màu (r,g,b,a) từ 0.0f -> 1.0f (0 -> 255).
* @param layer Vẽ ở lớp thứ mấy.
*/
        void DrawLine(const std::vector<VECTOR2>& listNode, const float& size, const VECTOR3& angle, const VECTOR4& color, const UINT& layer = 0);

        /**
    * @brief Vẽ Hình Vuông lên cửa sổ trò chơi.
    *
    * @param position Vị trí của hình vuông trên cửa sổ.
    * @param edge Chiều dài cạnh của hình vuông.
    * @param angle Góc xoay của hình vuông.
    * @param color Mã màu (r,g,b,a) từ 0 -> 255 của hình vuông.
    * @param pivot Điểm neo của hình vuông.
    * @param layer Vẽ ở lớp thứ mấy.
    */
        void DrawSquare(const VECTOR3& position, const float& edge, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
    * @brief Vẽ Hình Vuông lên cửa sổ trò chơi.
    *
    * @param position Vị trí của hình vuông trên cửa sổ.
    * @param edge Chiều dài cạnh của hình vuông.
    * @param angle Góc xoay của hình vuông.
    * @param color Mã màu COLOR của hình vuông.
    * @param pivot Điểm neo của hình vuông.
    * @param layer Vẽ ở lớp thứ mấy.
    */
        void DrawSquare(const VECTOR3& position, const float& edge, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
    * @brief Vẽ Hình Chữ Nhật lên cửa sổ trò chơi.
    *
    * @param position Vị trí của hình Chữ Nhật trên cửa sổ.
    * @param edge Chiều dài cạnh của hình Chữ Nhật.
    * @param angle Góc xoay của hình Chữ Nhật.
    * @param color Mã màu (r,g,b,a) từ 0 -> 255 của hình Chữ Nhật.
    * @param pivot Điểm neo của hình Chữ Nhật.
    * @param layer Vẽ ở lớp thứ mấy.
    */
        void DrawRectangle(const VECTOR3& position, const VECTOR2& edges, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
    * @brief Vẽ Hình Chữ Nhật lên cửa sổ trò chơi.
    *
    * @param position Vị trí của hình Chữ Nhật trên cửa sổ.
    * @param edge Chiều dài cạnh của hình Chữ Nhật.
    * @param angle Góc xoay của hình Chữ Nhật.
    * @param color Mã màu COLOR của hình Chữ Nhật.
    * @param pivot Điểm neo của hình Chữ Nhật.
    * @param layer Vẽ ở lớp thứ mấy.
    */
        void DrawRectangle(const VECTOR3& position, const VECTOR2& edges, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
    * @brief Vẽ Hình Tam Giác lên cửa sổ trò chơi.
    *
    * @param a,b,c Vị trí các đỉnh của hình Tam Giác trên cửa sổ.
    * @param angle Góc xoay của hình Tam Giác.
    * @param color Mã màu COLOR của hình Tam Giác.
    * @param pivot Điểm neo của hình Tam Giác.
    * @param layer Vẽ ở lớp thứ mấy.
    */
        //void DrawTriangle(const VECTOR3& a, const VECTOR3& b, const VECTOR3& c, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
   * @brief Vẽ Hình Tam Giác lên cửa sổ trò chơi.
   *
   * @param a,b,c Vị trí các đỉnh của hình Tam Giác trên cửa sổ.
   * @param angle Góc xoay của hình Tam Giác.
   * @param color Mã màu (r,g,b,a) từ 0 -> 255 của hình Tam Giác.
   * @param pivot Điểm neo của hình Tam Giác.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        //void DrawTriangle(const VECTOR3& a, const VECTOR3& b, const VECTOR3& c, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
   * @brief Vẽ Hình Tròn lên cửa sổ trò chơi.
   *
   * @param position Vị trí của hình Tròn trên cửa sổ.
   * @param radius Bán kính của hình Tròn.
   * @param angle Góc xoay của hình Tròn.
   * @param color Mã màu (r,g,b,a) từ 0 -> 255 của hình Tròn.
   * @param pivot Điểm neo của hình Tròn.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawCircle(const VECTOR3& position, const float& radius, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0,0 }, const UINT& layer = 0);
        /**
   * @brief Vẽ Hình Tròn lên cửa sổ trò chơi.
   *
   * @param position Vị trí của hình Tròn trên cửa sổ.
   * @param radius Bán kính của hình Tròn.
   * @param angle Góc xoay của hình Tròn.
   * @param color Mã màu COLOR của hình Tròn.
   * @param pivot Điểm neo của hình Tròn.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawCircle(const VECTOR3& position, const float& radius, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0,0 }, const UINT& layer = 0);



        void DrawCylinder(const VECTOR3& position, const float& length, const float& radius, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);
        void DrawCylinder(const VECTOR3& position, const float& length, const float& radius, const VECTOR3& angle, const VECTOR4& color, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);

        void DrawCylinder(const DirectX::XMFLOAT4X4&, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);
        void DrawCylinder(const DirectX::XMFLOAT4X4&, const VECTOR4& color, const UINT& layer = 0);


        void DrawCone(const VECTOR3& position, const float& height, const float& radius, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);
        void DrawCone(const VECTOR3& position, const float& height, const float& radius, const VECTOR3& angle, const VECTOR4& color, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);

        void DrawCone(const DirectX::XMFLOAT4X4&, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);
        void DrawCone(const DirectX::XMFLOAT4X4&, const VECTOR4& color, const UINT& layer = 0);

        void DrawSphere(const VECTOR3& position, const float& radius, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);
        void DrawSphere(const VECTOR3& position, const float& radius, const VECTOR3& angle, const VECTOR4& color, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);

        void DrawSphere(const DirectX::XMFLOAT4X4&, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);
        void DrawSphere(const DirectX::XMFLOAT4X4&, const VECTOR4& color, const UINT& layer = 0);

        void DrawSurface(const VECTOR3& position, const float& radius, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);
        void DrawSurface(const VECTOR3& position, const float& radius, const VECTOR3& angle, const VECTOR4& color, const VECTOR3& pivot = { 0,0,0 }, const UINT& layer = 0);

        void DrawSurface(const DirectX::XMFLOAT4X4& transform, const COLOR& color = COLOR::DEFAULT, const UINT& layer = 0);
        void DrawSurface(const DirectX::XMFLOAT4X4& transform, const VECTOR4& color, const UINT& layer = 0);

        /**
   * @brief Vẽ Sprite đã load ảnh lên cửa sổ trò chơi.
   *
   * @param sprite Con trỏ đã được load ảnh.
   * @param position Vị trí của Sprite trên cửa sổ.
   * @param edges Kích thước của Sprite.
   * @param angle Góc xoay của Sprite.
   * @param color Mã màu (r,g,b,a) từ 0 -> 255 của Sprite.
   * @param pivot Điểm neo của Sprite.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawSprite(const pSprite& sprite, const VECTOR3& position, const VECTOR2& edges, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
   * @brief Vẽ Sprite đã load ảnh lên cửa sổ trò chơi.
   *
   * @param sprite Con trỏ đã được load ảnh.
   * @param position Vị trí của Sprite trên cửa sổ.
   * @param edges Kích thước của Sprite.
   * @param angle Góc xoay của Sprite.
   * @param color Mã màu COLOR của Sprite.
   * @param pivot Điểm neo của Sprite.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawSprite(const pSprite& sprite, const VECTOR3& position, const VECTOR2& edges, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);




        /**
   * @brief Vẽ 1 phần của Sprite đã load ảnh lên cửa sổ trò chơi.
   *
   * @param sprite Con trỏ đã được load ảnh.
   * @param position Vị trí của Sprite trên cửa sổ.
   * @param texPos Vị trí của Phần muốn vẽ trên Texture.
   * @param texSize Độ dài và rộng của Phần muốn vẽ trên Texture.
   * @param size Độ lớn muốn vẽ.
   * @param angle Góc xoay của Sprite.
   * @param color Mã màu (r,g,b,a) từ 0 -> 255 của Sprite.
   * @param pivot Điểm neo của Sprite.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawPartialTexture(const pSprite& sprite, const VECTOR3& position, const VECTOR2& texPos, const VECTOR2& texSize, const VECTOR2& size, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
   * @brief Vẽ 1 phần của Sprite đã load ảnh lên cửa sổ trò chơi.
   *
   * @param sprite Con trỏ đã được load ảnh.
   * @param position Vị trí của Sprite trên cửa sổ.
   * @param texPos Vị trí của Phần muốn vẽ trên Texture.
   * @param texSize Độ dài và rộng của Phần muốn vẽ trên Texture.
   * @param size Độ lớn muốn vẽ.
   * @param angle Góc xoay của Sprite.
   * @param color Mã màu COLOR của Sprite.
   * @param pivot Điểm neo của Sprite.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void DrawPartialTexture(const pSprite& sprite, const VECTOR3& position, const VECTOR2& texPos, const VECTOR2& texSize, const VECTOR2& size, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);

        /**
   * @brief Viết nội dung Text lên cửa sổ trò chơi.
   *
   * @param content Nội dung text(tiếng anh).
   * @param fontNum Kiểu font(0 -> 5).
   * @param position Vị trí của đoạn text.
   * @param size Độ lớn của đoạn text.
   * @param angle Góc xoay của đoạn text.
   * @param color Mã màu (r,g,b,a) từ 0 -> 255 của đoạn text.
   * @param pivot Điểm neo của đoạn text.
   * @param layer Vẽ ở lớp thứ mấy.
   */
        void Textout(const std::wstring& content, const UINT& fontNum, const VECTOR3& position, const float& size, const VECTOR3& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);
        /**
  * @brief Viết nội dung Text lên cửa sổ trò chơi.
  *
  * @param content Nội dung text(tiếng anh).
  * @param fontNum Kiểu font(0 -> 5).
  * @param position Vị trí của đoạn text.
  * @param size Độ lớn của đoạn text.
  * @param angle Góc xoay của đoạn text.
  * @param color Mã màu COLOR của đoạn text.
  * @param pivot Điểm neo của đoạn text.
  * @param layer Vẽ ở lớp thứ mấy.
  */
        void Textout(const std::wstring& content, const UINT& fontNum, const VECTOR3& position, const float& size, const VECTOR3& angle, const COLOR& color = COLOR::DEFAULT, const VECTOR2& pivot = { 0, 0 }, const UINT& layer = 0);


        void PlayAnimation(pAnimator animator, const VECTOR2& position, const float& size, const float& angle, const VECTOR4& color, const VECTOR2& pivot = { 0, 0 }, UINT layer = 0);


        /**
  * @brief Xem xét sự kiện va chạm của 2 hình tròn
  *
  * @param objA Vị trí hình tròn thứ nhất.
  * @param radiusA Bán kính của hình tròn thứ nhất.
  * @param objB Vị trí hình tròn thứ hai.
  * @param radiusB Bán kính của hình tròn thứ hai.
  * @return true nếu 2 hình tròn va chạm, false nếu không.
  */
        bool CircleVsCircle(const VECTOR2& objA, const float& radiusA, const VECTOR2& objB, const float& radiusB,
            VECTOR2& hitPos);
        /**
  * @brief Xem xét sự kiện va chạm của 2 hình chữ nhật
  *
  * @param centerRectA Vị trí hình chữ nhật thứ nhất.
  * @param halfEdgeRectA Một nửa chiều dài các cạnh của hình chữ nhật thứ nhất.
  * @param angleRectA Góc xoay của hình chữ nhật thứ nhất.
  * @param centerRectB Vị trí hình hình chữ nhật thứ hai.
  * @param halfEdgeRectB Một nửa chiều dài các cạnh của hình chữ nhật thứ hai.
  * @param angleRectA Góc xoay của hình chữ nhật thứ hai.
  *
  * @return true nếu 2 hình chữ nhật va chạm, false nếu không.
  */
        bool RectVsRect(const VECTOR2& centerRectA, const VECTOR2& halfEdgeRectA, const float& angleRectA,
            const VECTOR2& centerRectB, const VECTOR2& halfEdgeRectB, const float& angleRectB);
        /**
  * @brief Xem xét sự kiện va chạm của 2 hình chữ nhật
  *
  * @param centerRectA Vị trí hình chữ nhật thứ nhất.
  * @param halfEdgeRectA Một nửa chiều dài các cạnh của hình chữ nhật thứ nhất.
  * @param centerRectB Vị trí hình hình chữ nhật thứ hai.
  * @param halfEdgeRectB Một nửa chiều dài các cạnh của hình chữ nhật thứ hai.
  * @param hitRect Nếu 2 hình chữ nhật va chạm, hitRect thể hiện độ dài của hình chữ nhật xâm lấn.
  *
  * @return true nếu 2 hình chữ nhật va chạm, false nếu không.
  */
        bool RectVsRect(const VECTOR2& centerRectA, const VECTOR2& halfEdgeRectA,
            const VECTOR2& centerRectB, const VECTOR2& halfEdgeRectB, VECTOR2* hitRect);
        /**
 * @brief Xem xét sự kiện va chạm của 1 tia với 1 hình chữ nhật
 *
 * @param rayBegin Vị trí bắt đầu của tia.
 * @param rayEnd Vị trí kết thúc của tia.
 * @param centerRect Vị trí hình hình chữ nhật.
 * @param halfEdgeRect Một nửa chiều dài các cạnh của hình chữ nhật.
 * @param dis Nếu tia va chạm với hình chữ nhật, dis thể hiện tỉ lệ phần xâm lấn của độ dài của tia.
 *
 * @return true nếu tia va chạm với hình chữ nhật, false nếu không.
 */
        bool RayVsRect(const VECTOR2& rayBegin, const VECTOR2& rayEnd,
            const VECTOR2& centerRect, const VECTOR2& halfEdgeRect, float* dis = nullptr);

        //Camera
    public:
        CameraHandle CreateCamera(const float& width, const float& height, const float& nearZ, const float& farZ, bool camera2D = true, float camera3DAngle = 60);
        void SetCameraPosition(const VECTOR3& positon);
        void AddCameraPosition(const VECTOR3& add);
        void AddCameraFocus(const VECTOR3& focus);
        void SetCameraFocus(const VECTOR3& focus);
        void CameraZoom(const float& zoomValue);

        VECTOR3 GetCameraPosition();
        VECTOR3 GetCameraUp();
        VECTOR3 GetCameraFocus();
        //Math
    public:
        VECTOR3 Random(const VECTOR3& min, const VECTOR3& max);
        float Random(const float& min, const float& max);
        int Random(const int& min, const int& max);
        float Length(const VECTOR2& v);
        float Length(const VECTOR3& v);
        float ConvertToRadian(const float& angle);
        float ConvertToDegrees(const float& angle);
        VECTOR3 Normalize(const VECTOR3& vec);
        VECTOR3 ConvertVectorToEuler(const VECTOR3& vec);
        float AngleBetweenVectorReturnRadian(const VECTOR3& v1, const VECTOR3& v2);
        VECTOR3 Cross(const VECTOR3& v1, const VECTOR3& v2);
        float Dot(const VECTOR3& v1, const VECTOR3& v2);
        VECTOR3 Clamp(const VECTOR3& v, const VECTOR3& lo, const VECTOR3& hi);
        VECTOR3 Clamp(const VECTOR3& v, const float& lo, const float& hi);
        VECTOR2 Clamp(const VECTOR2& v, const float& lo, const float& hi);
        ~BanGame();
    //Network
    public:
        void WebsocketConnect(const std::string& uri);
        NETWORKSTATUS GetNetworkStatus();
        void NetworkSendData(const nlohmann::json& data);
        void NetworkDeleteDataBuffer(const std::string& event);
        nlohmann::json NetworkGetData(const std::string& event);
        const double& GetPing();



    private:
        BanGame(BanGame const&) = delete;
        BanGame& operator=(BanGame const&) = delete;
        BanGame();
        void Init();
        VECTOR4 RGBColor(const COLOR& color);
        //static BanGame* instance_;
        static BanGame* instance_;

        // ImGui
    private:
        void ImGuiSetup();
        void ImGuiUninstall();

        void ImGuiRender();
        void ImGuiNewFrame();
    public:
        void ImGuiDragFloat1(const std::string& tableName, const std::string& name, float& float1, const float& step = 1.f);
        void ImGuiDragFloat2(const std::string& tableName, const std::string& name, VECTOR2& float2, const float& step = 1.f);
        void ImGuiDragFloat3(const std::string& tableName, const std::string& name, VECTOR3& float3, const float& step = 1.f);
        void ImGuiDragFloat4(const std::string& tableName, const std::string& name, VECTOR4& float4, const float& step = 1.f);

        void ImGuiColor4Edit(const std::string& tableName, const std::string& name, VECTOR4& color);
        void ImGuiText(const std::string& tableName, const std::string& content);
        void ImGuiSeparator(const std::string& tableName);
    private:
        void Render();
        void PresentFrame();
        void ReleaseQueue();
        void SetFocus(const bool&);

    public:

       

        //Input
       
        bool GetPress(KeyBoard::Keys keyNum);
        bool GetRelease(KeyBoard::Keys keyNum);
        bool GetTrigger(KeyBoard::Keys keyNum);
        bool GetPress(Mouse keyNum);
        bool GetRelease(Mouse keyNum);
        bool GetTrigger(Mouse keyNum);

        float GetWheel();
        float GetViewSize();

        const VECTOR2& GetMousePosition();
        const VECTOR2& GetOldMousePosition();

        const wchar_t& GetInputBuffer();
        
        //Screen
    public:
        VECTOR2 GetScreenSize();
        void SetFullscreen(const bool&);

    private:
        bool quitGame;
        bool focusing;
    };
}


#endif // !BANGAME_H
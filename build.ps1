g++ src\main.cpp src\RigidBody.cpp src\vec2.cpp `
    -I"C:\Users\benel\dev\Cpp\Projects\Physics-Engine\include" `
    -I"C:\Users\benel\dev\Cpp\Packages\GCC_15.2.0\SFML\include" `
    -L"C:\Users\benel\dev\Cpp\Packages\GCC_15.2.0\SFML\build\lib" `
    -DSFML_STATIC `
    -lsfml-graphics-s -lfreetype -lsfml-window-s -lsfml-system-s -lsfml-main `
    -lopengl32 -lgdi32 -lwinmm -limm32 -ldxguid `
    -o app.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build successful! Running app..."
    .\app.exe
} else {
    Write-Host "Build failed!"
}
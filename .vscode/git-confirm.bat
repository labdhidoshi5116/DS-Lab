@echo off
set /p commitMessage="Do you want to commit and push? (leave empty to cancel): "

if "%commitMessage%"=="" (
    echo Skipping commit...
    exit /b
)

git add .
git commit -m "%commitMessage%"
git push
pause

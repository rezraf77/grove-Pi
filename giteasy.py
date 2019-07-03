from os import system

print("GitEasy ver 1.0")
while True:
    command = input(">> ")                  #change this to what you want your prompt to look like

    if command == "commit" :
        mesg = input("Enter message :")
        system("git add -A")
        command2 = "git commit -m \" " + mesg + "\""
        system(command2)

    elif command == "push":
        system("git push")
    
    elif command == "status":
        system("git status")
    
    else:
        system(command)

#End of While

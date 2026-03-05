print("Turing Test Simulation (type 'exit' to quit)")

while True:
    user = input("You: ").lower()

    if user == "exit":
        break
    elif user == "hello":
        print("Machine: Hello! How are you?")
    elif user == "how are you":
        print("Machine: I am functioning normally.")
    elif user == "what is your name":
        print("Machine: I am a simple AI chatbot.")
    elif user == "what is ai":
        print("Machine: AI stands for Artificial Intelligence.")
    else:
        print("Machine: That sounds interesting. Tell me more.")
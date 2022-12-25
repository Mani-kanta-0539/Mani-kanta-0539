import pyttsx3
engine = pyttsx3.init()
voices = engine.getProperty('voices')       #getting details of current voice
#engine.setProperty('voice', voices[0].id)  #changing index, changes voices. o for male
engine.setProperty('voice', voices[1].id)   #changing index, changes voices. 1 for female


while True:
    t=input()
    engine.say(t)
    engine.runAndWait()
    
    

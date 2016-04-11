from time import strftime
from xml.dom import minidom

def addlog(cmd,msg,ans):
    doc = minidom.Document()
    data = doc.createElement("data")
    doc.appendChild(data)

    date = doc.createElement("date")
    date.appendChild(doc.createTextNode(strftime('%Y-%m-%d %H:%M:%S')))
    data.appendChild(date)

    command = doc.createElement("command")
    command.appendChild(doc.createTextNode(cmd))
    data.appendChild(command)

    message = doc.createElement("message")
    message.appendChild(doc.createTextNode(msg))
    data.appendChild(message)

    answer = doc.createElement("answer")
    answer.appendChild(doc.createTextNode(ans))
    data.appendChild(answer)

    f = open('log.xml','a')
    doc.writexml(f)
    f.close()
addlog('cmd','msg','ans')
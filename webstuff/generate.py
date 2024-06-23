import os

def generateRow(image, alt, fname, date):
    template = f"""
            <tr>
                <td valign="top">
                    <img src="/icons/{image}" alt="[{alt}]">
                </td>
                <td>
                    <a href="{fname}/">{fname}/</a>
                </td>    
                <td align="right">{date}  </td>
                <td align="right">- </td>
            </tr>"""
    return template

image = (input("Which icon: ") + ".gif")
alt = input("Which alt: ")
fname = input("Folder or file name: ")
date = input("Date: ")

newblock = generateRow(image, alt, fname, date)

with open("template.html", "a", encoding="utf-8") as f:
    f.write(newblock)
    f.close()

print(newblock)
from tbselenium.tbdriver import TorBrowserDriver
import proxy
import random

### Driver setup
driver = TorBrowserDriver("/home/octavcosmin/Files/tor-browser_en-US")

# while 1:
#     driver.load_url('https://check.torproject.org', wait_for_page_body=True)
#     time.sleep(3)
#     proxy.fresh_identity()
#     driver.refresh()

def vote():
    driver.load_url('https://docs.google.com/forms/d/e/1FAIpQLSfw-iWlyH0Zk2qKnKo-nLD3tdMxS_-s2hk6RqEEf7Hs-7BWqg/viewform', wait_for_page_body=True)
    check_boxes = driver.find_elements_by_class_name("exportInnerBox")
## Genul (0-1)
    # 0 - Masculin
    # 1 - Feminin
## Clasa (2-9)
    # 2 - a V-a
    # 3 - a VI-a
    # 4 - a VII-a
    # 5 - a VIII-a
    # 6 - a IX-a
    # 7 - a X-a
    # 8 - a XI-a
    # 9 - a XII-a
## Dificultati
    # 10 - Am o afecțiune cronică ce creşte riscul de complicaţii în cazul infecţiei cu COVID-19
    # 11 - Locuiesc cu persoane în vârstă/ cu afecţiuni cronice, vulnerabile la infecţia cu COVID-19
    # 12 - Trebuie să folosesc zilnic mijloacele de transport public
    # 13 - Nu voi putea purta masca de protecţie pe toata durata programului şcolar
    # 14 - Nu este cazul/Nu am dificultăţi
    check_boxes[random.randint(0,1)].click()
    check_boxes[random.randint(2,9)].click()
    check_boxes[random.randint(10,14)].click()

    radial_boxes = driver.find_elements_by_class_name("exportOuterCircle")
## Scenariul cel mai potrivit
    # 0 - Cursuri cu prezenţa fizică a tuturor elevilor şi cadrelor didactice în clase (scenariul verde)
    # 1 - Cursuri cu prezența fizică parțială a elevilor și a cadrelor didactice și on line parțial (scenariul galben)
    # 2 - Cursuri complet on line (scenariul roşu)
    # 3 - Nu ştiu/nu pot aprecia
    radial_boxes[1].click()

    text_areas = driver.find_elements_by_class_name("quantumWizTextinputPapertextareaInput.exportTextarea")
    text_areas[0].send_keys("☕")
    text_areas[1].send_keys("☕")

    submit_button = driver.find_element_by_class_name("appsMaterialWizButtonPaperbuttonLabel.quantumWizButtonPaperbuttonLabel.exportLabel")
    submit_button.click()

counter = 0
failed = 0
while True:
    try:
        vote()
    except:
        failed += 1
        pass
    counter += 1
    print("Votes: ", counter, "\nFailed: ", failed)
    proxy.fresh_identity()
    print("New Tor identity - ", proxy.get_ip())
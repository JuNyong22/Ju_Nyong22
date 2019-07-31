"""네이버 뉴스 기사 웹 크롤러 모듈"""

from bs4 import BeautifulSoup
import urllib.request
from datetime import datetime
import re
import os


# 긁어 올 URL
URL = 'https://news.naver.com/main/read.nhn?mode=LSD&mid=shm&sid1=103&oid=055&aid=0000445667'


# 크롤링 함수
#뉴스 입력 날짜
def get_date(URL):
    source_code_from_URL = urllib.request.urlopen(URL)
    soup = BeautifulSoup(source_code_from_URL, 'lxml', from_encoding='utf-8')
    text = ''
    for item in soup.find_all('span', class_='t11'):
        date_text = text + str(item.find_all(text=True))

    clean_date = re.sub('[\{\}\[\]\/?,;|\)*~`!^\-_+<>@\#$%&\\\=\(\'\"]', '', date_text)
    clean_date = clean_date.replace(':', '시 ')

    return clean_date

# 제목 크롤링
def get_title(URL):
    source_code_from_URL = urllib.request.urlopen(URL)
    soup = BeautifulSoup(source_code_from_URL, 'lxml', from_encoding='utf-8')
    text = ''
    for item in soup.find_all('h3', id='articleTitle'):
        text = text + str(item.find_all(text=True))

    # 제목 클리닝 함수
    cleaned_title = re.sub('\\n\\t', '', text)
    cleaned_title = cleaned_title.replace('[\'', '')
    cleaned_title = cleaned_title.replace('\']', '')
    cleaned_title = cleaned_title.lstrip()
    cleaned_title = re.sub('[\/\\?:|*<>\"]', '_', cleaned_title)

    return cleaned_title

# 본문 크롤링
def get_text(URL):
    global cleaned_text
    global text
    source_code_from_URL = urllib.request.urlopen(URL)
    soup = BeautifulSoup(source_code_from_URL, 'lxml', from_encoding='utf-8')
    text = ''
    for item in soup.find_all('div', id='articleBodyContents'):
        text = text + str(item.find_all(text=True))

    # 본문 클리닝 함수
    #cleaned_text = re.sub('[a-zA-Z]', '', text)
    cleaned_text = re.sub('[\{\}\/?;:|*~`!^-_+<>@\#$%&\=\"]',
                          '', text)

    cleaned_text = cleaned_text.replace('오류를 우회하기 위한 함수 추가', '').replace('본문 내용', '')
    cleaned_text = cleaned_text.replace('TV플레이어', '').replace('사진뉴스1', '')
    cleaned_text = cleaned_text.replace('사진뉴스2', '').replace('사진뉴스3', '')
    cleaned_text = cleaned_text.replace('동영상 뉴스', '').replace('.\', \'', '.\n')
    cleaned_text = cleaned_text.replace('\\n', '').replace('flash function flashremoveCallback()', '')
    cleaned_text = cleaned_text.replace('tt', '').replace('\\t', '').replace(' , ', '').replace('[\'', '')
    cleaned_text = cleaned_text.replace('\\\'', '\'').replace('., \'', '.\n').replace(', ', '')
    cleaned_text = cleaned_text.replace('\', \'', '').replace('.\\', '').replace('\']', '').replace('.\'', '.\n')
    if cleaned_text[0:1] == '\'':
        cleaned_text = cleaned_text.replace('\'', '')
    cleaned_text = cleaned_text.lstrip()
    if cleaned_text[0:2] == ', ':
        cleaned_text = cleaned_text.replace(', ', '')
        cleaned_text = cleaned_text.lstrip()
    cleaned_text = cleaned_text.replace('., ', '.\n').replace('. ', '.\n')
    cleaned_text = cleaned_text.replace('\\xa0', '\n').replace('\n ', '\n')

    return cleaned_text


    # 신문사 제목 크롤링
def get_company(URL):
    get_text(URL)
    mystr = cleaned_text
    search = "ⓒ"

    indexno = mystr.find(search)
    company = mystr[indexno + 1: indexno + 12]

    # 총 신문사 이름
    all_newscompany = ["경향신문", "국민일보", "노컷뉴스", "뉴데일리", "뉴스타파", "뉴시스", "데일리안", "동아일보",
                            "디지털자임스", "마이데일리", "매일경제", "머니투데이", "문화일보", "미디어오늘", "블로터",
                            "서울경제 서울신문", "세계일보", "스포츠동아", "스포츠서울", "스포츠조선", "스포탈코리아",
                            "시사인", "아시아경제", "아이뉴스24", "연합뉴스TV", "오마이뉴스", "이데일리", "일간스포츠",
                            "전자신문", "조선비즈", "조선일보", "중앙데일리", "중앙일보", "지디넷코리아", "지지통신",
                            "코리아헤럴드", "파이낸셜뉴스", "프레시안", "한겨레", "한국경제TV", "한국경제", "한국일보",
                            "헤럴드경제", "JTBC", "KBS", "KBS World", "MBC", "MBN", "OSEN", "SBS", "YTN", "건설경제",
                            "나우뉴스", "뉴스토마토", "뉴스핌", "더팩트", "데이터뉴스", "매일노동뉴스", "머니에스", "메트로",
                            "미디어펜", "브릿지경제", "비즈니스워치", "비즈니스포스트", "비즈한국", "소비자가 만드는 신문",
                            "시사위크", "시사저널이코노미", "신아일보", "아시아투데이", "아주경제", "에너지경제", "연합이노맥스",
                            "위키리크스한국", "위키트리", "이뉴스투데이", "이코노미스트", "이투데이", "인더스트리뉴스", "인민망",
                            "일요시사", "일요신문", "조세일보", "중앙SUNDAY", "초이스경제", "쿠키뉴스", "한국금융", "허프포스트",
                            "BBS NEWS", "CEO스코어데일리", "CNB뉴스", "이비엔", "M이코노미", "PD저널", "뉴스1", "머니투데이방송",
                            "arirang", "채널A", "CNN", "EBS교육방송", "KBC 광주방송", "KNN", "OBS", "SBSCNBC", "대구경북TBC",
                            "TV조선", "YTN 사이언스", "TBS", "넥스트데일리", "디지털데일리", "보안뉴스", "키튜스", "헬로디디",
                            "IT조선", "YONHAPNEWS", "뉴스엔", "스타뉴스", "스포츠Q", "스포츠경향", "스포츠월드", "스포츠투데이",
                            "스포츠한국", "스포티비뉴스", "엑스포츠뉴스", "앰스플뉴스", "조이뉴스24", "텐아시아", "TV데일리",
                            "MK스포츠", "SBS 연예스포츠", "TV리포트", "enews24", "게임메카", "동아사이언스", "국방일보",
                            "그린포스트코리아", "낚시춘추", "농민신문", "뉴스컬처", "더스쿠프", "DAILY NK", "데일리 한국",
                            "독서신문", "디자인 정글", "르몽드", "매경이코노미", "맥스무비", "법률신문", "베리타스알파", "사이언스타임즈",
                            "산업일보", "소년한국일보", "시사저널", "씨네21", "약사공론", "에이블뉴스", "엘르", "여성신문", "월간중앙",
                            "이웃집과학자", "이코노미조선", "인벤", "인사이트코리아", "자동차생활", "전기신문", "정신의학신문", "주간조선",
                            "채널예스", "철강금속신문", "컴퓨터월드", "코리아쉬핑가제트", "코메디닷컴", "투데이신문", "포브스코리아",
                            "한겨레21", "한국경제매거진", "한국대학신문", "헬스조선", "MONEY", "PC사랑", "TheAsiaN", "강원도민일보",
                            "강원일보", "경기일보", "경남신문", "경북도민일보", "경북매일신문", "경북일보", "경상일보", "경인일보", "광주드림",
                            "광주일보", "국제신문", "기호일보", "대구일보", "대전일보", "매일신문", "무등일보", "부산일보", "영남일보",
                            "인천일보", "전남일보", "전북도민일보", "전북일보", "제민일보", "제주도민일보", "제주의소리", "중도일보", "중보매일",
                            "중부일보", "충북일보", "충청일보", "충청투데이", "한라일보"]

    i = 0

    for i in range(0, 209):
        if all_newscompany[i] in company:
            company = all_newscompany[i]

            return company
        i += 1

# 메인 함수
def main():
    result_date = get_date(URL)
    result_text = get_text(URL)
    result_title = get_title(URL)
    result_company = get_company(URL)

    #파일이 없으면 생성
    RESULT_PATH = 'D:/크롤링/' + result_company + '/'
    if not os.path.isdir(RESULT_PATH):
        os.mkdir(RESULT_PATH)

    # 출력 파일 명
    OUTPUT_FILE_NAME = RESULT_PATH + result_date + '분 ' + result_company + " " + result_title + '.txt'
    open_output_file = open(OUTPUT_FILE_NAME, 'w')
    open_output_file.write(result_text)
    open_output_file.close()
    # print(get_company(URL))

if __name__ == "__main__":
    main()

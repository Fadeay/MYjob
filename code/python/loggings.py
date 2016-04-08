# -*- coding: utf-8 -*-
import logging

class classlog(object):
    """log class"""
    def __init__(self,logfilename="log.txt"):
        self.logger = logging.getLogger("classlog")
        self.logger.setLevel(logging.DEBUG)
        Fileformatter = logging.Formatter("%(asctime)s - %(name)s - %(levelname)-8s: - %(message)s",datefmt='%Y-%m-%d %I:%M:%S %p')
        Streamformatter = logging.Formatter("%(levelname)s:%(message)s")# ,filename='example.log')


        Filelog = logging.FileHandler(logfilename)
        Filelog.setFormatter(Fileformatter)
        Filelog.setLevel(logging.ERROR)

        Streamlog = logging.StreamHandler()
        Streamlog.setFormatter(Streamformatter)
        Streamlog.setLevel(logging.ERROR)

        self.logger.addHandler(Filelog)
        self.logger.addHandler(Streamlog)

    def debug(self,msg):
        self.logger.debug(msg)

    def info(self,msg):
        self.logger.info(msg)

    def warn(self,msg):
        self.logger.warn(msg)

    def error(self,msg):
        self.logger.error(msg)

    def critical(self,msg):
        self.logger.critical(msg)
a=classlog()
a.info("fhd")
a.debug("fhd")
a.error("fhd")
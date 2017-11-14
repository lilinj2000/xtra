void TraderSpiImpl::OnFrontConnected() {
	SOIL_FUNC_TRACE;
}

void TraderSpiImpl::OnFrontDisconnected(
	int nReason) {
	SOIL_FUNC_TRACE;

	SOIL_DEBUG_PRINT(nReason);
}

void TraderSpiImpl::OnPackageStart(
	int nTopicID,
	int nSequenceNo) {
	SOIL_FUNC_TRACE;

	SOIL_DEBUG_PRINT(nTopicID);
	SOIL_DEBUG_PRINT(nSequenceNo);
}

void TraderSpiImpl::OnPackageEnd(
	int nTopicID,
	int nSequenceNo) {
	SOIL_FUNC_TRACE;

	SOIL_DEBUG_PRINT(nTopicID);
	SOIL_DEBUG_PRINT(nSequenceNo);
}

void TraderSpiImpl::OnRspError(
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspError(
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspUserLogin(
	CXeleFtdcRspUserLoginField* pRspUserLogin,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspUserLogin(
			pRspUserLogin ? fmt::format("{}", *pRspUserLogin) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspUserLogout(
	CXeleFtdcRspUserLogoutField* pRspUserLogout,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspUserLogout(
			pRspUserLogout ? fmt::format("{}", *pRspUserLogout) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspOrderInsert(
	CXeleFtdcInputOrderField* pInputOrder,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspOrderInsert(
			pInputOrder ? fmt::format("{}", *pInputOrder) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspOrderAction(
	CXeleFtdcOrderActionField* pOrderAction,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspOrderAction(
			pOrderAction ? fmt::format("{}", *pOrderAction) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryClientPosition(
	CXeleFtdcRspClientPositionField* pRspClientPosition,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryClientPosition(
			pRspClientPosition ? fmt::format("{}", *pRspClientPosition) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryInstrument(
	CXeleFtdcRspInstrumentField* pRspInstrument,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryInstrument(
			pRspInstrument ? fmt::format("{}", *pRspInstrument) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryClientAccount(
	CXeleFtdcRspClientAccountField* pClientAccount,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryClientAccount(
			pClientAccount ? fmt::format("{}", *pClientAccount) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryInstrumentMarginRate(
	CXeleFtdcRspInstrumentMarginRateField* pRspInstrumentMarginRate,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryInstrumentMarginRate(
			pRspInstrumentMarginRate ? fmt::format("{}", *pRspInstrumentMarginRate) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryInstrumentCommissionRate(
	CXeleFtdcRspInstrumentCommissionRateField* pRspInstrumentCommissionRate,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryInstrumentCommissionRate(
			pRspInstrumentCommissionRate ? fmt::format("{}", *pRspInstrumentCommissionRate) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspUserPasswordUpdate(
	CXeleFtdcUserPasswordUpdateField* pUserPasswordUpdate,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspUserPasswordUpdate(
			pUserPasswordUpdate ? fmt::format("{}", *pUserPasswordUpdate) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRtnTrade(
	CXeleFtdcTradeField* pTrade) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRtnTrade(
			pTrade ? fmt::format("{}", *pTrade) : "");
	}
}

void TraderSpiImpl::OnRtnOrder(
	CXeleFtdcOrderField* pOrder) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRtnOrder(
			pOrder ? fmt::format("{}", *pOrder) : "");
	}
}

void TraderSpiImpl::OnRtnInstrumentStatus(
	CXeleFtdcInstrumentStatusField* pInstrumentStatus) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRtnInstrumentStatus(
			pInstrumentStatus ? fmt::format("{}", *pInstrumentStatus) : "");
	}
}

void TraderSpiImpl::OnRtnInsInstrument(
	CXeleFtdcInstrumentField* pInstrument) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRtnInsInstrument(
			pInstrument ? fmt::format("{}", *pInstrument) : "");
	}
}

void TraderSpiImpl::OnErrRtnOrderInsert(
	CXeleFtdcInputOrderField* pInputOrder,
	CXeleFtdcRspInfoField* pRspInfo) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onErrRtnOrderInsert(
			pInputOrder ? fmt::format("{}", *pInputOrder) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "");
	}
}

void TraderSpiImpl::OnErrRtnOrderAction(
	CXeleFtdcOrderActionField* pOrderAction,
	CXeleFtdcRspInfoField* pRspInfo) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onErrRtnOrderAction(
			pOrderAction ? fmt::format("{}", *pOrderAction) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "");
	}
}

void TraderSpiImpl::OnRspQryOrder(
	CXeleFtdcOrderField* pOrderField,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryOrder(
			pOrderField ? fmt::format("{}", *pOrderField) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryTrade(
	CXeleFtdcTradeField* pTradeField,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryTrade(
			pTradeField ? fmt::format("{}", *pTradeField) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspInstrumentPrice(
	CXeleFtdcRspInstrumentPriceField* pTradeField,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspInstrumentPrice(
			pTradeField ? fmt::format("{}", *pTradeField) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}

void TraderSpiImpl::OnRspQryExchangeFront(
	CXeleFtdcRspExchangeFrontField* pRspExchangeFront,
	CXeleFtdcRspInfoField* pRspInfo,
	int nRequestID,
	bool bIsLast) {
	SOIL_FUNC_TRACE;

	if (callback()) {
		callback()->onRspQryExchangeFront(
			pRspExchangeFront ? fmt::format("{}", *pRspExchangeFront) : "",
			pRspInfo ? fmt::format("{}", *pRspInfo) : "",
			nRequestID,
			bIsLast);
	}
}


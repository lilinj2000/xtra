#ifndef CXELE_FTDC_USERAPI_STRUCT_PRINT_HH
#define CXELE_FTDC_USERAPI_STRUCT_PRINT_HH

#include <ostream>
#include "CXeleFtdcUserApiStruct.h"

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcDisseminationField const& aDisseminationField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcDisseminationField\": {" <<std::endl;
    os <<"        \"SequenceSeries\": \"" <<aDisseminationField.SequenceSeries  <<"\"," <<std::endl;
    os <<"        \"SequenceNo\": \"" <<aDisseminationField.SequenceNo  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspInfoField const& aRspInfoField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspInfoField\": {" <<std::endl;
    os <<"        \"ErrorID\": \"" <<aRspInfoField.ErrorID  <<"\"," <<std::endl;
    os <<"        \"ErrorMsg\": \"" <<aRspInfoField.ErrorMsg  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcReqUserLoginField const& aReqUserLoginField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcReqUserLoginField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aReqUserLoginField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aReqUserLoginField.UserID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aReqUserLoginField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"Password\": \"" <<aReqUserLoginField.Password  <<"\"," <<std::endl;
    os <<"        \"UserProductInfo\": \"" <<aReqUserLoginField.UserProductInfo  <<"\"," <<std::endl;
    os <<"        \"InterfaceProductInfo\": \"" <<aReqUserLoginField.InterfaceProductInfo  <<"\"," <<std::endl;
    os <<"        \"ProtocolInfo\": \"" <<aReqUserLoginField.ProtocolInfo  <<"\"," <<std::endl;
    os <<"        \"DataCenterID\": \"" <<aReqUserLoginField.DataCenterID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspUserLoginField const& aRspUserLoginField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspUserLoginField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aRspUserLoginField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"LoginTime\": \"" <<aRspUserLoginField.LoginTime  <<"\"," <<std::endl;
    os <<"        \"MaxOrderLocalID\": \"" <<aRspUserLoginField.MaxOrderLocalID  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aRspUserLoginField.UserID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aRspUserLoginField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"TradingSystemName\": \"" <<aRspUserLoginField.TradingSystemName  <<"\"," <<std::endl;
    os <<"        \"DataCenterID\": \"" <<aRspUserLoginField.DataCenterID  <<"\"," <<std::endl;
    os <<"        \"PrivateFlowSize\": \"" <<aRspUserLoginField.PrivateFlowSize  <<"\"," <<std::endl;
    os <<"        \"UserFlowSize\": \"" <<aRspUserLoginField.UserFlowSize  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcReqUserLogoutField const& aReqUserLogoutField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcReqUserLogoutField\": {" <<std::endl;
    os <<"        \"UserID\": \"" <<aReqUserLogoutField.UserID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aReqUserLogoutField.ParticipantID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspUserLogoutField const& aRspUserLogoutField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspUserLogoutField\": {" <<std::endl;
    os <<"        \"UserID\": \"" <<aRspUserLogoutField.UserID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aRspUserLogoutField.ParticipantID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcInputOrderField const& aInputOrderField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcInputOrderField\": {" <<std::endl;
    os <<"        \"OrderSysID\": \"" <<aInputOrderField.OrderSysID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aInputOrderField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aInputOrderField.ClientID  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aInputOrderField.UserID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aInputOrderField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"OrderPriceType\": \"" <<aInputOrderField.OrderPriceType  <<"\"," <<std::endl;
    os <<"        \"Direction\": \"" <<aInputOrderField.Direction  <<"\"," <<std::endl;
    os <<"        \"CombOffsetFlag\": \"" <<aInputOrderField.CombOffsetFlag  <<"\"," <<std::endl;
    os <<"        \"CombHedgeFlag\": \"" <<aInputOrderField.CombHedgeFlag  <<"\"," <<std::endl;
    os <<"        \"LimitPrice\": \"" <<aInputOrderField.LimitPrice  <<"\"," <<std::endl;
    os <<"        \"VolumeTotalOriginal\": \"" <<aInputOrderField.VolumeTotalOriginal  <<"\"," <<std::endl;
    os <<"        \"TimeCondition\": \"" <<aInputOrderField.TimeCondition  <<"\"," <<std::endl;
    os <<"        \"GTDDate\": \"" <<aInputOrderField.GTDDate  <<"\"," <<std::endl;
    os <<"        \"VolumeCondition\": \"" <<aInputOrderField.VolumeCondition  <<"\"," <<std::endl;
    os <<"        \"MinVolume\": \"" <<aInputOrderField.MinVolume  <<"\"," <<std::endl;
    os <<"        \"ContingentCondition\": \"" <<aInputOrderField.ContingentCondition  <<"\"," <<std::endl;
    os <<"        \"StopPrice\": \"" <<aInputOrderField.StopPrice  <<"\"," <<std::endl;
    os <<"        \"ForceCloseReason\": \"" <<aInputOrderField.ForceCloseReason  <<"\"," <<std::endl;
    os <<"        \"OrderLocalID\": \"" <<aInputOrderField.OrderLocalID  <<"\"," <<std::endl;
    os <<"        \"IsAutoSuspend\": \"" <<aInputOrderField.IsAutoSuspend  <<"\"," <<std::endl;
    os <<"        \"ExchangeOrderSysID\": \"" <<aInputOrderField.ExchangeOrderSysID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcOrderActionField const& aOrderActionField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcOrderActionField\": {" <<std::endl;
    os <<"        \"OrderSysID\": \"" <<aOrderActionField.OrderSysID  <<"\"," <<std::endl;
    os <<"        \"OrderLocalID\": \"" <<aOrderActionField.OrderLocalID  <<"\"," <<std::endl;
    os <<"        \"ActionFlag\": \"" <<aOrderActionField.ActionFlag  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aOrderActionField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aOrderActionField.ClientID  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aOrderActionField.UserID  <<"\"," <<std::endl;
    os <<"        \"LimitPrice\": \"" <<aOrderActionField.LimitPrice  <<"\"," <<std::endl;
    os <<"        \"VolumeChange\": \"" <<aOrderActionField.VolumeChange  <<"\"," <<std::endl;
    os <<"        \"ActionLocalID\": \"" <<aOrderActionField.ActionLocalID  <<"\"," <<std::endl;
    os <<"        \"BusinessUnit\": \"" <<aOrderActionField.BusinessUnit  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcUserPasswordUpdateField const& aUserPasswordUpdateField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcUserPasswordUpdateField\": {" <<std::endl;
    os <<"        \"UserID\": \"" <<aUserPasswordUpdateField.UserID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aUserPasswordUpdateField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"OldPassword\": \"" <<aUserPasswordUpdateField.OldPassword  <<"\"," <<std::endl;
    os <<"        \"NewPassword\": \"" <<aUserPasswordUpdateField.NewPassword  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryOrderField const& aQryOrderField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryOrderField\": {" <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryOrderField.ClientID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryOrderField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"OrderSysID\": \"" <<aQryOrderField.OrderSysID  <<"\"," <<std::endl;
    os <<"        \"TimeStart\": \"" <<aQryOrderField.TimeStart  <<"\"," <<std::endl;
    os <<"        \"TimeEnd\": \"" <<aQryOrderField.TimeEnd  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryTradeField const& aQryTradeField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryTradeField\": {" <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryTradeField.ClientID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryTradeField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"TradeID\": \"" <<aQryTradeField.TradeID  <<"\"," <<std::endl;
    os <<"        \"TimeStart\": \"" <<aQryTradeField.TimeStart  <<"\"," <<std::endl;
    os <<"        \"TimeEnd\": \"" <<aQryTradeField.TimeEnd  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryMarketDataField const& aQryMarketDataField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryMarketDataField\": {" <<std::endl;
    os <<"        \"ProductID\": \"" <<aQryMarketDataField.ProductID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryMarketDataField.InstrumentID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryClientPositionField const& aQryClientPositionField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryClientPositionField\": {" <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryClientPositionField.ClientID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryClientPositionField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientType\": \"" <<aQryClientPositionField.ClientType  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryInstrumentField const& aQryInstrumentField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryInstrumentField\": {" <<std::endl;
    os <<"        \"ProductID\": \"" <<aQryInstrumentField.ProductID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryInstrumentField.InstrumentID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspClientPositionField const& aRspClientPositionField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspClientPositionField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aRspClientPositionField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aRspClientPositionField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aRspClientPositionField.SettlementID  <<"\"," <<std::endl;
    os <<"        \"HedgeFlag\": \"" <<aRspClientPositionField.HedgeFlag  <<"\"," <<std::endl;
    os <<"        \"PosiDirection\": \"" <<aRspClientPositionField.PosiDirection  <<"\"," <<std::endl;
    os <<"        \"YdPosition\": \"" <<aRspClientPositionField.YdPosition  <<"\"," <<std::endl;
    os <<"        \"Position\": \"" <<aRspClientPositionField.Position  <<"\"," <<std::endl;
    os <<"        \"LongFrozen\": \"" <<aRspClientPositionField.LongFrozen  <<"\"," <<std::endl;
    os <<"        \"ShortFrozen\": \"" <<aRspClientPositionField.ShortFrozen  <<"\"," <<std::endl;
    os <<"        \"YdLongFrozen\": \"" <<aRspClientPositionField.YdLongFrozen  <<"\"," <<std::endl;
    os <<"        \"YdShortFrozen\": \"" <<aRspClientPositionField.YdShortFrozen  <<"\"," <<std::endl;
    os <<"        \"BuyTradeVolume\": \"" <<aRspClientPositionField.BuyTradeVolume  <<"\"," <<std::endl;
    os <<"        \"SellTradeVolume\": \"" <<aRspClientPositionField.SellTradeVolume  <<"\"," <<std::endl;
    os <<"        \"PositionCost\": \"" <<aRspClientPositionField.PositionCost  <<"\"," <<std::endl;
    os <<"        \"YdPositionCost\": \"" <<aRspClientPositionField.YdPositionCost  <<"\"," <<std::endl;
    os <<"        \"UseMargin\": \"" <<aRspClientPositionField.UseMargin  <<"\"," <<std::endl;
    os <<"        \"FrozenMargin\": \"" <<aRspClientPositionField.FrozenMargin  <<"\"," <<std::endl;
    os <<"        \"LongFrozenMargin\": \"" <<aRspClientPositionField.LongFrozenMargin  <<"\"," <<std::endl;
    os <<"        \"ShortFrozenMargin\": \"" <<aRspClientPositionField.ShortFrozenMargin  <<"\"," <<std::endl;
    os <<"        \"FrozenPremium\": \"" <<aRspClientPositionField.FrozenPremium  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aRspClientPositionField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aRspClientPositionField.ClientID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspInstrumentField const& aRspInstrumentField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspInstrumentField\": {" <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aRspInstrumentField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"ProductID\": \"" <<aRspInstrumentField.ProductID  <<"\"," <<std::endl;
    os <<"        \"ProductGroupID\": \"" <<aRspInstrumentField.ProductGroupID  <<"\"," <<std::endl;
    os <<"        \"UnderlyingInstrID\": \"" <<aRspInstrumentField.UnderlyingInstrID  <<"\"," <<std::endl;
    os <<"        \"ProductClass\": \"" <<aRspInstrumentField.ProductClass  <<"\"," <<std::endl;
    os <<"        \"PositionType\": \"" <<aRspInstrumentField.PositionType  <<"\"," <<std::endl;
    os <<"        \"StrikePrice\": \"" <<aRspInstrumentField.StrikePrice  <<"\"," <<std::endl;
    os <<"        \"OptionsType\": \"" <<aRspInstrumentField.OptionsType  <<"\"," <<std::endl;
    os <<"        \"VolumeMultiple\": \"" <<aRspInstrumentField.VolumeMultiple  <<"\"," <<std::endl;
    os <<"        \"UnderlyingMultiple\": \"" <<aRspInstrumentField.UnderlyingMultiple  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aRspInstrumentField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"InstrumentName\": \"" <<aRspInstrumentField.InstrumentName  <<"\"," <<std::endl;
    os <<"        \"DeliveryYear\": \"" <<aRspInstrumentField.DeliveryYear  <<"\"," <<std::endl;
    os <<"        \"DeliveryMonth\": \"" <<aRspInstrumentField.DeliveryMonth  <<"\"," <<std::endl;
    os <<"        \"AdvanceMonth\": \"" <<aRspInstrumentField.AdvanceMonth  <<"\"," <<std::endl;
    os <<"        \"IsTrading\": \"" <<aRspInstrumentField.IsTrading  <<"\"," <<std::endl;
    os <<"        \"CreateDate\": \"" <<aRspInstrumentField.CreateDate  <<"\"," <<std::endl;
    os <<"        \"OpenDate\": \"" <<aRspInstrumentField.OpenDate  <<"\"," <<std::endl;
    os <<"        \"ExpireDate\": \"" <<aRspInstrumentField.ExpireDate  <<"\"," <<std::endl;
    os <<"        \"StartDelivDate\": \"" <<aRspInstrumentField.StartDelivDate  <<"\"," <<std::endl;
    os <<"        \"EndDelivDate\": \"" <<aRspInstrumentField.EndDelivDate  <<"\"," <<std::endl;
    os <<"        \"BasisPrice\": \"" <<aRspInstrumentField.BasisPrice  <<"\"," <<std::endl;
    os <<"        \"MaxMarketOrderVolume\": \"" <<aRspInstrumentField.MaxMarketOrderVolume  <<"\"," <<std::endl;
    os <<"        \"MinMarketOrderVolume\": \"" <<aRspInstrumentField.MinMarketOrderVolume  <<"\"," <<std::endl;
    os <<"        \"MaxLimitOrderVolume\": \"" <<aRspInstrumentField.MaxLimitOrderVolume  <<"\"," <<std::endl;
    os <<"        \"MinLimitOrderVolume\": \"" <<aRspInstrumentField.MinLimitOrderVolume  <<"\"," <<std::endl;
    os <<"        \"PriceTick\": \"" <<aRspInstrumentField.PriceTick  <<"\"," <<std::endl;
    os <<"        \"AllowDelivPersonOpen\": \"" <<aRspInstrumentField.AllowDelivPersonOpen  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcInstrumentField const& aInstrumentField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcInstrumentField\": {" <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aInstrumentField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"ProductID\": \"" <<aInstrumentField.ProductID  <<"\"," <<std::endl;
    os <<"        \"ProductGroupID\": \"" <<aInstrumentField.ProductGroupID  <<"\"," <<std::endl;
    os <<"        \"UnderlyingInstrID\": \"" <<aInstrumentField.UnderlyingInstrID  <<"\"," <<std::endl;
    os <<"        \"ProductClass\": \"" <<aInstrumentField.ProductClass  <<"\"," <<std::endl;
    os <<"        \"PositionType\": \"" <<aInstrumentField.PositionType  <<"\"," <<std::endl;
    os <<"        \"StrikePrice\": \"" <<aInstrumentField.StrikePrice  <<"\"," <<std::endl;
    os <<"        \"OptionsType\": \"" <<aInstrumentField.OptionsType  <<"\"," <<std::endl;
    os <<"        \"VolumeMultiple\": \"" <<aInstrumentField.VolumeMultiple  <<"\"," <<std::endl;
    os <<"        \"UnderlyingMultiple\": \"" <<aInstrumentField.UnderlyingMultiple  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aInstrumentField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"InstrumentName\": \"" <<aInstrumentField.InstrumentName  <<"\"," <<std::endl;
    os <<"        \"DeliveryYear\": \"" <<aInstrumentField.DeliveryYear  <<"\"," <<std::endl;
    os <<"        \"DeliveryMonth\": \"" <<aInstrumentField.DeliveryMonth  <<"\"," <<std::endl;
    os <<"        \"AdvanceMonth\": \"" <<aInstrumentField.AdvanceMonth  <<"\"," <<std::endl;
    os <<"        \"IsTrading\": \"" <<aInstrumentField.IsTrading  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcTradeField const& aTradeField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcTradeField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aTradeField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aTradeField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aTradeField.SettlementID  <<"\"," <<std::endl;
    os <<"        \"TradeID\": \"" <<aTradeField.TradeID  <<"\"," <<std::endl;
    os <<"        \"Direction\": \"" <<aTradeField.Direction  <<"\"," <<std::endl;
    os <<"        \"OrderSysID\": \"" <<aTradeField.OrderSysID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aTradeField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aTradeField.ClientID  <<"\"," <<std::endl;
    os <<"        \"TradingRole\": \"" <<aTradeField.TradingRole  <<"\"," <<std::endl;
    os <<"        \"AccountID\": \"" <<aTradeField.AccountID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aTradeField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"OffsetFlag\": \"" <<aTradeField.OffsetFlag  <<"\"," <<std::endl;
    os <<"        \"HedgeFlag\": \"" <<aTradeField.HedgeFlag  <<"\"," <<std::endl;
    os <<"        \"Price\": \"" <<aTradeField.Price  <<"\"," <<std::endl;
    os <<"        \"Volume\": \"" <<aTradeField.Volume  <<"\"," <<std::endl;
    os <<"        \"TradeTime\": \"" <<aTradeField.TradeTime  <<"\"," <<std::endl;
    os <<"        \"TradeType\": \"" <<aTradeField.TradeType  <<"\"," <<std::endl;
    os <<"        \"PriceSource\": \"" <<aTradeField.PriceSource  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aTradeField.UserID  <<"\"," <<std::endl;
    os <<"        \"OrderLocalID\": \"" <<aTradeField.OrderLocalID  <<"\"," <<std::endl;
    os <<"        \"ClearingPartID\": \"" <<aTradeField.ClearingPartID  <<"\"," <<std::endl;
    os <<"        \"BusinessUnit\": \"" <<aTradeField.BusinessUnit  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcOrderField const& aOrderField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcOrderField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aOrderField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aOrderField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aOrderField.SettlementID  <<"\"," <<std::endl;
    os <<"        \"OrderSysID\": \"" <<aOrderField.OrderSysID  <<"\"," <<std::endl;
    os <<"        \"ParticipantID\": \"" <<aOrderField.ParticipantID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aOrderField.ClientID  <<"\"," <<std::endl;
    os <<"        \"UserID\": \"" <<aOrderField.UserID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aOrderField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"OrderPriceType\": \"" <<aOrderField.OrderPriceType  <<"\"," <<std::endl;
    os <<"        \"Direction\": \"" <<aOrderField.Direction  <<"\"," <<std::endl;
    os <<"        \"CombOffsetFlag\": \"" <<aOrderField.CombOffsetFlag  <<"\"," <<std::endl;
    os <<"        \"CombHedgeFlag\": \"" <<aOrderField.CombHedgeFlag  <<"\"," <<std::endl;
    os <<"        \"LimitPrice\": \"" <<aOrderField.LimitPrice  <<"\"," <<std::endl;
    os <<"        \"VolumeTotalOriginal\": \"" <<aOrderField.VolumeTotalOriginal  <<"\"," <<std::endl;
    os <<"        \"TimeCondition\": \"" <<aOrderField.TimeCondition  <<"\"," <<std::endl;
    os <<"        \"GTDDate\": \"" <<aOrderField.GTDDate  <<"\"," <<std::endl;
    os <<"        \"VolumeCondition\": \"" <<aOrderField.VolumeCondition  <<"\"," <<std::endl;
    os <<"        \"MinVolume\": \"" <<aOrderField.MinVolume  <<"\"," <<std::endl;
    os <<"        \"ContingentCondition\": \"" <<aOrderField.ContingentCondition  <<"\"," <<std::endl;
    os <<"        \"StopPrice\": \"" <<aOrderField.StopPrice  <<"\"," <<std::endl;
    os <<"        \"ForceCloseReason\": \"" <<aOrderField.ForceCloseReason  <<"\"," <<std::endl;
    os <<"        \"OrderLocalID\": \"" <<aOrderField.OrderLocalID  <<"\"," <<std::endl;
    os <<"        \"IsAutoSuspend\": \"" <<aOrderField.IsAutoSuspend  <<"\"," <<std::endl;
    os <<"        \"OrderSource\": \"" <<aOrderField.OrderSource  <<"\"," <<std::endl;
    os <<"        \"OrderStatus\": \"" <<aOrderField.OrderStatus  <<"\"," <<std::endl;
    os <<"        \"OrderType\": \"" <<aOrderField.OrderType  <<"\"," <<std::endl;
    os <<"        \"VolumeTraded\": \"" <<aOrderField.VolumeTraded  <<"\"," <<std::endl;
    os <<"        \"VolumeTotal\": \"" <<aOrderField.VolumeTotal  <<"\"," <<std::endl;
    os <<"        \"InsertDate\": \"" <<aOrderField.InsertDate  <<"\"," <<std::endl;
    os <<"        \"InsertTime\": \"" <<aOrderField.InsertTime  <<"\"," <<std::endl;
    os <<"        \"ActiveTime\": \"" <<aOrderField.ActiveTime  <<"\"," <<std::endl;
    os <<"        \"SuspendTime\": \"" <<aOrderField.SuspendTime  <<"\"," <<std::endl;
    os <<"        \"UpdateTime\": \"" <<aOrderField.UpdateTime  <<"\"," <<std::endl;
    os <<"        \"CancelTime\": \"" <<aOrderField.CancelTime  <<"\"," <<std::endl;
    os <<"        \"ActiveUserID\": \"" <<aOrderField.ActiveUserID  <<"\"," <<std::endl;
    os <<"        \"Priority\": \"" <<aOrderField.Priority  <<"\"," <<std::endl;
    os <<"        \"TimeSortID\": \"" <<aOrderField.TimeSortID  <<"\"," <<std::endl;
    os <<"        \"ClearingPartID\": \"" <<aOrderField.ClearingPartID  <<"\"," <<std::endl;
    os <<"        \"BusinessUnit\": \"" <<aOrderField.BusinessUnit  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcInstrumentStatusField const& aInstrumentStatusField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcInstrumentStatusField\": {" <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aInstrumentStatusField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aInstrumentStatusField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"InstrumentStatus\": \"" <<aInstrumentStatusField.InstrumentStatus  <<"\"," <<std::endl;
    os <<"        \"TradingSegmentSN\": \"" <<aInstrumentStatusField.TradingSegmentSN  <<"\"," <<std::endl;
    os <<"        \"EnterTime\": \"" <<aInstrumentStatusField.EnterTime  <<"\"," <<std::endl;
    os <<"        \"EnterReason\": \"" <<aInstrumentStatusField.EnterReason  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryClientAccountField const& aQryClientAccountField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryClientAccountField\": {" <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryClientAccountField.ClientID  <<"\"," <<std::endl;
    os <<"        \"AccountID\": \"" <<aQryClientAccountField.AccountID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspClientAccountField const& aRspClientAccountField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspClientAccountField\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aRspClientAccountField.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aRspClientAccountField.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aRspClientAccountField.SettlementID  <<"\"," <<std::endl;
    os <<"        \"PreBalance\": \"" <<aRspClientAccountField.PreBalance  <<"\"," <<std::endl;
    os <<"        \"CurrMargin\": \"" <<aRspClientAccountField.CurrMargin  <<"\"," <<std::endl;
    os <<"        \"CloseProfit\": \"" <<aRspClientAccountField.CloseProfit  <<"\"," <<std::endl;
    os <<"        \"Premium\": \"" <<aRspClientAccountField.Premium  <<"\"," <<std::endl;
    os <<"        \"Deposit\": \"" <<aRspClientAccountField.Deposit  <<"\"," <<std::endl;
    os <<"        \"Withdraw\": \"" <<aRspClientAccountField.Withdraw  <<"\"," <<std::endl;
    os <<"        \"Balance\": \"" <<aRspClientAccountField.Balance  <<"\"," <<std::endl;
    os <<"        \"Available\": \"" <<aRspClientAccountField.Available  <<"\"," <<std::endl;
    os <<"        \"AccountID\": \"" <<aRspClientAccountField.AccountID  <<"\"," <<std::endl;
    os <<"        \"FrozenMargin\": \"" <<aRspClientAccountField.FrozenMargin  <<"\"," <<std::endl;
    os <<"        \"FrozenPremium\": \"" <<aRspClientAccountField.FrozenPremium  <<"\"," <<std::endl;
    os <<"        \"BaseReserve\": \"" <<aRspClientAccountField.BaseReserve  <<"\"," <<std::endl;
    os <<"        \"floatProfitAndLoss\": \"" <<aRspClientAccountField.floatProfitAndLoss  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryInstrumentMarginRateField const& aQryInstrumentMarginRateField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryInstrumentMarginRateField\": {" <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryInstrumentMarginRateField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryInstrumentMarginRateField.ClientID  <<"\"," <<std::endl;
    os <<"        \"HedgeFlag\": \"" <<aQryInstrumentMarginRateField.HedgeFlag  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspInstrumentMarginRateField const& aRspInstrumentMarginRateField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspInstrumentMarginRateField\": {" <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aRspInstrumentMarginRateField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aRspInstrumentMarginRateField.ClientID  <<"\"," <<std::endl;
    os <<"        \"HedgeFlag\": \"" <<aRspInstrumentMarginRateField.HedgeFlag  <<"\"," <<std::endl;
    os <<"        \"LongMarginRatioByMoney\": \"" <<aRspInstrumentMarginRateField.LongMarginRatioByMoney  <<"\"," <<std::endl;
    os <<"        \"LongMarginRatioByVolume\": \"" <<aRspInstrumentMarginRateField.LongMarginRatioByVolume  <<"\"," <<std::endl;
    os <<"        \"ShortMarginRatioByMoney\": \"" <<aRspInstrumentMarginRateField.ShortMarginRatioByMoney  <<"\"," <<std::endl;
    os <<"        \"ShortMarginRatioByVolume\": \"" <<aRspInstrumentMarginRateField.ShortMarginRatioByVolume  <<"\"," <<std::endl;
    os <<"        \"IsRelative\": \"" <<aRspInstrumentMarginRateField.IsRelative  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryInstrumentCommissionRateField const& aQryInstrumentCommissionRateField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryInstrumentCommissionRateField\": {" <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aQryInstrumentCommissionRateField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aQryInstrumentCommissionRateField.ClientID  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcRspInstrumentCommissionRateField const& aRspInstrumentCommissionRateField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcRspInstrumentCommissionRateField\": {" <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aRspInstrumentCommissionRateField.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"ClientID\": \"" <<aRspInstrumentCommissionRateField.ClientID  <<"\"," <<std::endl;
    os <<"        \"OpenRatioByMoney\": \"" <<aRspInstrumentCommissionRateField.OpenRatioByMoney  <<"\"," <<std::endl;
    os <<"        \"OpenRatioByVolume\": \"" <<aRspInstrumentCommissionRateField.OpenRatioByVolume  <<"\"," <<std::endl;
    os <<"        \"CloseRatioByMoney\": \"" <<aRspInstrumentCommissionRateField.CloseRatioByMoney  <<"\"," <<std::endl;
    os <<"        \"CloseRatioByVolume\": \"" <<aRspInstrumentCommissionRateField.CloseRatioByVolume  <<"\"," <<std::endl;
    os <<"        \"CloseTodayRatioByMoney\": \"" <<aRspInstrumentCommissionRateField.CloseTodayRatioByMoney  <<"\"," <<std::endl;
    os <<"        \"CloseTodayRatioByVolume\": \"" <<aRspInstrumentCommissionRateField.CloseTodayRatioByVolume  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CXeleFtdcQryInstrumentStatusField const& aQryInstrumentStatusField)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CXeleFtdcQryInstrumentStatusField\": {" <<std::endl;
    os <<"        \"InstIDStart\": \"" <<aQryInstrumentStatusField.InstIDStart  <<"\"," <<std::endl;
    os <<"        \"InstIDEnd\": \"" <<aQryInstrumentStatusField.InstIDEnd  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

#endif // CXELE_FTDC_USERAPI_STRUCT_PRINT_HH

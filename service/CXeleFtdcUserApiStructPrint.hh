// Copyright (c) 2010
// All rights reserved.

#ifndef CXELE_FTDC_USERAPI_STRUCT_PRINT_HH
#define CXELE_FTDC_USERAPI_STRUCT_PRINT_HH

#include <ostream>
#include "CXeleFtdcUserApiStruct.h"
#include "soil/json.hh"

using rapidjson::StringBuffer;
using rapidjson::PrettyWriter;
using soil::json::write_value;

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcDisseminationField const& aDisseminationField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcDisseminationField");
        writer.StartObject();
        writer.Key("SequenceSeries");
        write_value(
            &writer,
            aDisseminationField.SequenceSeries);
        writer.Key("SequenceNo");
        write_value(
            &writer,
            aDisseminationField.SequenceNo);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspInfoField const& aRspInfoField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspInfoField");
        writer.StartObject();
        writer.Key("ErrorID");
        write_value(
            &writer,
            aRspInfoField.ErrorID);
        writer.Key("ErrorMsg");
        write_value(
            &writer,
            aRspInfoField.ErrorMsg);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcReqUserLoginField const& aReqUserLoginField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcReqUserLoginField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aReqUserLoginField.TradingDay);
        writer.Key("UserID");
        write_value(
            &writer,
            aReqUserLoginField.UserID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aReqUserLoginField.ParticipantID);
        writer.Key("Password");
        write_value(
            &writer,
            aReqUserLoginField.Password);
        writer.Key("UserProductInfo");
        write_value(
            &writer,
            aReqUserLoginField.UserProductInfo);
        writer.Key("InterfaceProductInfo");
        write_value(
            &writer,
            aReqUserLoginField.InterfaceProductInfo);
        writer.Key("ProtocolInfo");
        write_value(
            &writer,
            aReqUserLoginField.ProtocolInfo);
        writer.Key("DataCenterID");
        write_value(
            &writer,
            aReqUserLoginField.DataCenterID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspUserLoginField const& aRspUserLoginField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspUserLoginField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aRspUserLoginField.TradingDay);
        writer.Key("LoginTime");
        write_value(
            &writer,
            aRspUserLoginField.LoginTime);
        writer.Key("MaxOrderLocalID");
        write_value(
            &writer,
            aRspUserLoginField.MaxOrderLocalID);
        writer.Key("UserID");
        write_value(
            &writer,
            aRspUserLoginField.UserID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aRspUserLoginField.ParticipantID);
        writer.Key("TradingSystemName");
        write_value(
            &writer,
            aRspUserLoginField.TradingSystemName);
        writer.Key("DataCenterID");
        write_value(
            &writer,
            aRspUserLoginField.DataCenterID);
        writer.Key("PrivateFlowSize");
        write_value(
            &writer,
            aRspUserLoginField.PrivateFlowSize);
        writer.Key("UserFlowSize");
        write_value(
            &writer,
            aRspUserLoginField.UserFlowSize);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcReqUserLogoutField const& aReqUserLogoutField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcReqUserLogoutField");
        writer.StartObject();
        writer.Key("UserID");
        write_value(
            &writer,
            aReqUserLogoutField.UserID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aReqUserLogoutField.ParticipantID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspUserLogoutField const& aRspUserLogoutField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspUserLogoutField");
        writer.StartObject();
        writer.Key("UserID");
        write_value(
            &writer,
            aRspUserLogoutField.UserID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aRspUserLogoutField.ParticipantID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcInputOrderField const& aInputOrderField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcInputOrderField");
        writer.StartObject();
        writer.Key("OrderSysID");
        write_value(
            &writer,
            aInputOrderField.OrderSysID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aInputOrderField.ParticipantID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aInputOrderField.ClientID);
        writer.Key("UserID");
        write_value(
            &writer,
            aInputOrderField.UserID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aInputOrderField.InstrumentID);
        writer.Key("OrderPriceType");
        write_value(
            &writer,
            aInputOrderField.OrderPriceType);
        writer.Key("Direction");
        write_value(
            &writer,
            aInputOrderField.Direction);
        writer.Key("CombOffsetFlag");
        write_value(
            &writer,
            aInputOrderField.CombOffsetFlag);
        writer.Key("CombHedgeFlag");
        write_value(
            &writer,
            aInputOrderField.CombHedgeFlag);
        writer.Key("LimitPrice");
        write_value(
            &writer,
            aInputOrderField.LimitPrice);
        writer.Key("VolumeTotalOriginal");
        write_value(
            &writer,
            aInputOrderField.VolumeTotalOriginal);
        writer.Key("TimeCondition");
        write_value(
            &writer,
            aInputOrderField.TimeCondition);
        writer.Key("GTDDate");
        write_value(
            &writer,
            aInputOrderField.GTDDate);
        writer.Key("VolumeCondition");
        write_value(
            &writer,
            aInputOrderField.VolumeCondition);
        writer.Key("MinVolume");
        write_value(
            &writer,
            aInputOrderField.MinVolume);
        writer.Key("ContingentCondition");
        write_value(
            &writer,
            aInputOrderField.ContingentCondition);
        writer.Key("StopPrice");
        write_value(
            &writer,
            aInputOrderField.StopPrice);
        writer.Key("ForceCloseReason");
        write_value(
            &writer,
            aInputOrderField.ForceCloseReason);
        writer.Key("OrderLocalID");
        write_value(
            &writer,
            aInputOrderField.OrderLocalID);
        writer.Key("IsAutoSuspend");
        write_value(
            &writer,
            aInputOrderField.IsAutoSuspend);
        writer.Key("ExchangeOrderSysID");
        write_value(
            &writer,
            aInputOrderField.ExchangeOrderSysID);
        writer.Key("ExchangeFront");
        write_value(
            &writer,
            aInputOrderField.ExchangeFront);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcOrderActionField const& aOrderActionField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcOrderActionField");
        writer.StartObject();
        writer.Key("OrderSysID");
        write_value(
            &writer,
            aOrderActionField.OrderSysID);
        writer.Key("OrderLocalID");
        write_value(
            &writer,
            aOrderActionField.OrderLocalID);
        writer.Key("ActionFlag");
        write_value(
            &writer,
            aOrderActionField.ActionFlag);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aOrderActionField.ParticipantID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aOrderActionField.ClientID);
        writer.Key("UserID");
        write_value(
            &writer,
            aOrderActionField.UserID);
        writer.Key("LimitPrice");
        write_value(
            &writer,
            aOrderActionField.LimitPrice);
        writer.Key("VolumeChange");
        write_value(
            &writer,
            aOrderActionField.VolumeChange);
        writer.Key("ActionLocalID");
        write_value(
            &writer,
            aOrderActionField.ActionLocalID);
        writer.Key("BusinessUnit");
        write_value(
            &writer,
            aOrderActionField.BusinessUnit);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcUserPasswordUpdateField const& aUserPasswordUpdateField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcUserPasswordUpdateField");
        writer.StartObject();
        writer.Key("UserID");
        write_value(
            &writer,
            aUserPasswordUpdateField.UserID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aUserPasswordUpdateField.ParticipantID);
        writer.Key("OldPassword");
        write_value(
            &writer,
            aUserPasswordUpdateField.OldPassword);
        writer.Key("NewPassword");
        write_value(
            &writer,
            aUserPasswordUpdateField.NewPassword);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryOrderField const& aQryOrderField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryOrderField");
        writer.StartObject();
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryOrderField.ClientID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryOrderField.InstrumentID);
        writer.Key("OrderSysID");
        write_value(
            &writer,
            aQryOrderField.OrderSysID);
        writer.Key("TimeStart");
        write_value(
            &writer,
            aQryOrderField.TimeStart);
        writer.Key("TimeEnd");
        write_value(
            &writer,
            aQryOrderField.TimeEnd);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryTradeField const& aQryTradeField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryTradeField");
        writer.StartObject();
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryTradeField.ClientID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryTradeField.InstrumentID);
        writer.Key("TradeID");
        write_value(
            &writer,
            aQryTradeField.TradeID);
        writer.Key("TimeStart");
        write_value(
            &writer,
            aQryTradeField.TimeStart);
        writer.Key("TimeEnd");
        write_value(
            &writer,
            aQryTradeField.TimeEnd);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryMarketDataField const& aQryMarketDataField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryMarketDataField");
        writer.StartObject();
        writer.Key("ProductID");
        write_value(
            &writer,
            aQryMarketDataField.ProductID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryMarketDataField.InstrumentID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryClientPositionField const& aQryClientPositionField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryClientPositionField");
        writer.StartObject();
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryClientPositionField.ClientID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryClientPositionField.InstrumentID);
        writer.Key("ClientType");
        write_value(
            &writer,
            aQryClientPositionField.ClientType);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryInstrumentField const& aQryInstrumentField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryInstrumentField");
        writer.StartObject();
        writer.Key("ProductID");
        write_value(
            &writer,
            aQryInstrumentField.ProductID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryInstrumentField.InstrumentID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspClientPositionField const& aRspClientPositionField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspClientPositionField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aRspClientPositionField.TradingDay);
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aRspClientPositionField.SettlementGroupID);
        writer.Key("SettlementID");
        write_value(
            &writer,
            aRspClientPositionField.SettlementID);
        writer.Key("HedgeFlag");
        write_value(
            &writer,
            aRspClientPositionField.HedgeFlag);
        writer.Key("PosiDirection");
        write_value(
            &writer,
            aRspClientPositionField.PosiDirection);
        writer.Key("YdPosition");
        write_value(
            &writer,
            aRspClientPositionField.YdPosition);
        writer.Key("Position");
        write_value(
            &writer,
            aRspClientPositionField.Position);
        writer.Key("LongFrozen");
        write_value(
            &writer,
            aRspClientPositionField.LongFrozen);
        writer.Key("ShortFrozen");
        write_value(
            &writer,
            aRspClientPositionField.ShortFrozen);
        writer.Key("YdLongFrozen");
        write_value(
            &writer,
            aRspClientPositionField.YdLongFrozen);
        writer.Key("YdShortFrozen");
        write_value(
            &writer,
            aRspClientPositionField.YdShortFrozen);
        writer.Key("BuyTradeVolume");
        write_value(
            &writer,
            aRspClientPositionField.BuyTradeVolume);
        writer.Key("SellTradeVolume");
        write_value(
            &writer,
            aRspClientPositionField.SellTradeVolume);
        writer.Key("PositionCost");
        write_value(
            &writer,
            aRspClientPositionField.PositionCost);
        writer.Key("YdPositionCost");
        write_value(
            &writer,
            aRspClientPositionField.YdPositionCost);
        writer.Key("UseMargin");
        write_value(
            &writer,
            aRspClientPositionField.UseMargin);
        writer.Key("FrozenMargin");
        write_value(
            &writer,
            aRspClientPositionField.FrozenMargin);
        writer.Key("LongFrozenMargin");
        write_value(
            &writer,
            aRspClientPositionField.LongFrozenMargin);
        writer.Key("ShortFrozenMargin");
        write_value(
            &writer,
            aRspClientPositionField.ShortFrozenMargin);
        writer.Key("FrozenPremium");
        write_value(
            &writer,
            aRspClientPositionField.FrozenPremium);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aRspClientPositionField.InstrumentID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aRspClientPositionField.ClientID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspInstrumentField const& aRspInstrumentField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspInstrumentField");
        writer.StartObject();
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aRspInstrumentField.SettlementGroupID);
        writer.Key("ProductID");
        write_value(
            &writer,
            aRspInstrumentField.ProductID);
        writer.Key("ProductGroupID");
        write_value(
            &writer,
            aRspInstrumentField.ProductGroupID);
        writer.Key("UnderlyingInstrID");
        write_value(
            &writer,
            aRspInstrumentField.UnderlyingInstrID);
        writer.Key("ProductClass");
        write_value(
            &writer,
            aRspInstrumentField.ProductClass);
        writer.Key("PositionType");
        write_value(
            &writer,
            aRspInstrumentField.PositionType);
        writer.Key("StrikePrice");
        write_value(
            &writer,
            aRspInstrumentField.StrikePrice);
        writer.Key("OptionsType");
        write_value(
            &writer,
            aRspInstrumentField.OptionsType);
        writer.Key("VolumeMultiple");
        write_value(
            &writer,
            aRspInstrumentField.VolumeMultiple);
        writer.Key("UnderlyingMultiple");
        write_value(
            &writer,
            aRspInstrumentField.UnderlyingMultiple);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aRspInstrumentField.InstrumentID);
        writer.Key("InstrumentName");
        write_value(
            &writer,
            aRspInstrumentField.InstrumentName);
        writer.Key("DeliveryYear");
        write_value(
            &writer,
            aRspInstrumentField.DeliveryYear);
        writer.Key("DeliveryMonth");
        write_value(
            &writer,
            aRspInstrumentField.DeliveryMonth);
        writer.Key("AdvanceMonth");
        write_value(
            &writer,
            aRspInstrumentField.AdvanceMonth);
        writer.Key("IsTrading");
        write_value(
            &writer,
            aRspInstrumentField.IsTrading);
        writer.Key("CreateDate");
        write_value(
            &writer,
            aRspInstrumentField.CreateDate);
        writer.Key("OpenDate");
        write_value(
            &writer,
            aRspInstrumentField.OpenDate);
        writer.Key("ExpireDate");
        write_value(
            &writer,
            aRspInstrumentField.ExpireDate);
        writer.Key("StartDelivDate");
        write_value(
            &writer,
            aRspInstrumentField.StartDelivDate);
        writer.Key("EndDelivDate");
        write_value(
            &writer,
            aRspInstrumentField.EndDelivDate);
        writer.Key("BasisPrice");
        write_value(
            &writer,
            aRspInstrumentField.BasisPrice);
        writer.Key("MaxMarketOrderVolume");
        write_value(
            &writer,
            aRspInstrumentField.MaxMarketOrderVolume);
        writer.Key("MinMarketOrderVolume");
        write_value(
            &writer,
            aRspInstrumentField.MinMarketOrderVolume);
        writer.Key("MaxLimitOrderVolume");
        write_value(
            &writer,
            aRspInstrumentField.MaxLimitOrderVolume);
        writer.Key("MinLimitOrderVolume");
        write_value(
            &writer,
            aRspInstrumentField.MinLimitOrderVolume);
        writer.Key("PriceTick");
        write_value(
            &writer,
            aRspInstrumentField.PriceTick);
        writer.Key("AllowDelivPersonOpen");
        write_value(
            &writer,
            aRspInstrumentField.AllowDelivPersonOpen);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcInstrumentField const& aInstrumentField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcInstrumentField");
        writer.StartObject();
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aInstrumentField.SettlementGroupID);
        writer.Key("ProductID");
        write_value(
            &writer,
            aInstrumentField.ProductID);
        writer.Key("ProductGroupID");
        write_value(
            &writer,
            aInstrumentField.ProductGroupID);
        writer.Key("UnderlyingInstrID");
        write_value(
            &writer,
            aInstrumentField.UnderlyingInstrID);
        writer.Key("ProductClass");
        write_value(
            &writer,
            aInstrumentField.ProductClass);
        writer.Key("PositionType");
        write_value(
            &writer,
            aInstrumentField.PositionType);
        writer.Key("StrikePrice");
        write_value(
            &writer,
            aInstrumentField.StrikePrice);
        writer.Key("OptionsType");
        write_value(
            &writer,
            aInstrumentField.OptionsType);
        writer.Key("VolumeMultiple");
        write_value(
            &writer,
            aInstrumentField.VolumeMultiple);
        writer.Key("UnderlyingMultiple");
        write_value(
            &writer,
            aInstrumentField.UnderlyingMultiple);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aInstrumentField.InstrumentID);
        writer.Key("InstrumentName");
        write_value(
            &writer,
            aInstrumentField.InstrumentName);
        writer.Key("DeliveryYear");
        write_value(
            &writer,
            aInstrumentField.DeliveryYear);
        writer.Key("DeliveryMonth");
        write_value(
            &writer,
            aInstrumentField.DeliveryMonth);
        writer.Key("AdvanceMonth");
        write_value(
            &writer,
            aInstrumentField.AdvanceMonth);
        writer.Key("IsTrading");
        write_value(
            &writer,
            aInstrumentField.IsTrading);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcTradeField const& aTradeField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcTradeField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aTradeField.TradingDay);
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aTradeField.SettlementGroupID);
        writer.Key("SettlementID");
        write_value(
            &writer,
            aTradeField.SettlementID);
        writer.Key("TradeID");
        write_value(
            &writer,
            aTradeField.TradeID);
        writer.Key("Direction");
        write_value(
            &writer,
            aTradeField.Direction);
        writer.Key("OrderSysID");
        write_value(
            &writer,
            aTradeField.OrderSysID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aTradeField.ParticipantID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aTradeField.ClientID);
        writer.Key("TradingRole");
        write_value(
            &writer,
            aTradeField.TradingRole);
        writer.Key("AccountID");
        write_value(
            &writer,
            aTradeField.AccountID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aTradeField.InstrumentID);
        writer.Key("OffsetFlag");
        write_value(
            &writer,
            aTradeField.OffsetFlag);
        writer.Key("HedgeFlag");
        write_value(
            &writer,
            aTradeField.HedgeFlag);
        writer.Key("Price");
        write_value(
            &writer,
            aTradeField.Price);
        writer.Key("Volume");
        write_value(
            &writer,
            aTradeField.Volume);
        writer.Key("TradeTime");
        write_value(
            &writer,
            aTradeField.TradeTime);
        writer.Key("TradeType");
        write_value(
            &writer,
            aTradeField.TradeType);
        writer.Key("PriceSource");
        write_value(
            &writer,
            aTradeField.PriceSource);
        writer.Key("UserID");
        write_value(
            &writer,
            aTradeField.UserID);
        writer.Key("OrderLocalID");
        write_value(
            &writer,
            aTradeField.OrderLocalID);
        writer.Key("ClearingPartID");
        write_value(
            &writer,
            aTradeField.ClearingPartID);
        writer.Key("BusinessUnit");
        write_value(
            &writer,
            aTradeField.BusinessUnit);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcOrderField const& aOrderField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcOrderField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aOrderField.TradingDay);
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aOrderField.SettlementGroupID);
        writer.Key("SettlementID");
        write_value(
            &writer,
            aOrderField.SettlementID);
        writer.Key("OrderSysID");
        write_value(
            &writer,
            aOrderField.OrderSysID);
        writer.Key("ParticipantID");
        write_value(
            &writer,
            aOrderField.ParticipantID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aOrderField.ClientID);
        writer.Key("UserID");
        write_value(
            &writer,
            aOrderField.UserID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aOrderField.InstrumentID);
        writer.Key("OrderPriceType");
        write_value(
            &writer,
            aOrderField.OrderPriceType);
        writer.Key("Direction");
        write_value(
            &writer,
            aOrderField.Direction);
        writer.Key("CombOffsetFlag");
        write_value(
            &writer,
            aOrderField.CombOffsetFlag);
        writer.Key("CombHedgeFlag");
        write_value(
            &writer,
            aOrderField.CombHedgeFlag);
        writer.Key("LimitPrice");
        write_value(
            &writer,
            aOrderField.LimitPrice);
        writer.Key("VolumeTotalOriginal");
        write_value(
            &writer,
            aOrderField.VolumeTotalOriginal);
        writer.Key("TimeCondition");
        write_value(
            &writer,
            aOrderField.TimeCondition);
        writer.Key("GTDDate");
        write_value(
            &writer,
            aOrderField.GTDDate);
        writer.Key("VolumeCondition");
        write_value(
            &writer,
            aOrderField.VolumeCondition);
        writer.Key("MinVolume");
        write_value(
            &writer,
            aOrderField.MinVolume);
        writer.Key("ContingentCondition");
        write_value(
            &writer,
            aOrderField.ContingentCondition);
        writer.Key("StopPrice");
        write_value(
            &writer,
            aOrderField.StopPrice);
        writer.Key("ForceCloseReason");
        write_value(
            &writer,
            aOrderField.ForceCloseReason);
        writer.Key("OrderLocalID");
        write_value(
            &writer,
            aOrderField.OrderLocalID);
        writer.Key("IsAutoSuspend");
        write_value(
            &writer,
            aOrderField.IsAutoSuspend);
        writer.Key("OrderSource");
        write_value(
            &writer,
            aOrderField.OrderSource);
        writer.Key("OrderStatus");
        write_value(
            &writer,
            aOrderField.OrderStatus);
        writer.Key("OrderType");
        write_value(
            &writer,
            aOrderField.OrderType);
        writer.Key("VolumeTraded");
        write_value(
            &writer,
            aOrderField.VolumeTraded);
        writer.Key("VolumeTotal");
        write_value(
            &writer,
            aOrderField.VolumeTotal);
        writer.Key("InsertDate");
        write_value(
            &writer,
            aOrderField.InsertDate);
        writer.Key("InsertTime");
        write_value(
            &writer,
            aOrderField.InsertTime);
        writer.Key("ActiveTime");
        write_value(
            &writer,
            aOrderField.ActiveTime);
        writer.Key("SuspendTime");
        write_value(
            &writer,
            aOrderField.SuspendTime);
        writer.Key("UpdateTime");
        write_value(
            &writer,
            aOrderField.UpdateTime);
        writer.Key("CancelTime");
        write_value(
            &writer,
            aOrderField.CancelTime);
        writer.Key("ActiveUserID");
        write_value(
            &writer,
            aOrderField.ActiveUserID);
        writer.Key("Priority");
        write_value(
            &writer,
            aOrderField.Priority);
        writer.Key("TimeSortID");
        write_value(
            &writer,
            aOrderField.TimeSortID);
        writer.Key("ClearingPartID");
        write_value(
            &writer,
            aOrderField.ClearingPartID);
        writer.Key("BusinessUnit");
        write_value(
            &writer,
            aOrderField.BusinessUnit);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcInstrumentStatusField const& aInstrumentStatusField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcInstrumentStatusField");
        writer.StartObject();
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aInstrumentStatusField.SettlementGroupID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aInstrumentStatusField.InstrumentID);
        writer.Key("InstrumentStatus");
        write_value(
            &writer,
            aInstrumentStatusField.InstrumentStatus);
        writer.Key("TradingSegmentSN");
        write_value(
            &writer,
            aInstrumentStatusField.TradingSegmentSN);
        writer.Key("EnterTime");
        write_value(
            &writer,
            aInstrumentStatusField.EnterTime);
        writer.Key("EnterReason");
        write_value(
            &writer,
            aInstrumentStatusField.EnterReason);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryClientAccountField const& aQryClientAccountField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryClientAccountField");
        writer.StartObject();
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryClientAccountField.ClientID);
        writer.Key("AccountID");
        write_value(
            &writer,
            aQryClientAccountField.AccountID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspClientAccountField const& aRspClientAccountField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspClientAccountField");
        writer.StartObject();
        writer.Key("TradingDay");
        write_value(
            &writer,
            aRspClientAccountField.TradingDay);
        writer.Key("SettlementGroupID");
        write_value(
            &writer,
            aRspClientAccountField.SettlementGroupID);
        writer.Key("SettlementID");
        write_value(
            &writer,
            aRspClientAccountField.SettlementID);
        writer.Key("PreBalance");
        write_value(
            &writer,
            aRspClientAccountField.PreBalance);
        writer.Key("CurrMargin");
        write_value(
            &writer,
            aRspClientAccountField.CurrMargin);
        writer.Key("CloseProfit");
        write_value(
            &writer,
            aRspClientAccountField.CloseProfit);
        writer.Key("Premium");
        write_value(
            &writer,
            aRspClientAccountField.Premium);
        writer.Key("Deposit");
        write_value(
            &writer,
            aRspClientAccountField.Deposit);
        writer.Key("Withdraw");
        write_value(
            &writer,
            aRspClientAccountField.Withdraw);
        writer.Key("Balance");
        write_value(
            &writer,
            aRspClientAccountField.Balance);
        writer.Key("Available");
        write_value(
            &writer,
            aRspClientAccountField.Available);
        writer.Key("AccountID");
        write_value(
            &writer,
            aRspClientAccountField.AccountID);
        writer.Key("FrozenMargin");
        write_value(
            &writer,
            aRspClientAccountField.FrozenMargin);
        writer.Key("FrozenPremium");
        write_value(
            &writer,
            aRspClientAccountField.FrozenPremium);
        writer.Key("BaseReserve");
        write_value(
            &writer,
            aRspClientAccountField.BaseReserve);
        writer.Key("floatProfitAndLoss");
        write_value(
            &writer,
            aRspClientAccountField.floatProfitAndLoss);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryInstrumentMarginRateField const& aQryInstrumentMarginRateField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryInstrumentMarginRateField");
        writer.StartObject();
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryInstrumentMarginRateField.InstrumentID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryInstrumentMarginRateField.ClientID);
        writer.Key("HedgeFlag");
        write_value(
            &writer,
            aQryInstrumentMarginRateField.HedgeFlag);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspInstrumentMarginRateField const& aRspInstrumentMarginRateField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspInstrumentMarginRateField");
        writer.StartObject();
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.InstrumentID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.ClientID);
        writer.Key("HedgeFlag");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.HedgeFlag);
        writer.Key("LongMarginRatioByMoney");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.LongMarginRatioByMoney);
        writer.Key("LongMarginRatioByVolume");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.LongMarginRatioByVolume);
        writer.Key("ShortMarginRatioByMoney");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.ShortMarginRatioByMoney);
        writer.Key("ShortMarginRatioByVolume");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.ShortMarginRatioByVolume);
        writer.Key("IsRelative");
        write_value(
            &writer,
            aRspInstrumentMarginRateField.IsRelative);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryInstrumentCommissionRateField const& aQryInstrumentCommissionRateField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryInstrumentCommissionRateField");
        writer.StartObject();
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aQryInstrumentCommissionRateField.InstrumentID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aQryInstrumentCommissionRateField.ClientID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspInstrumentCommissionRateField const& aRspInstrumentCommissionRateField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspInstrumentCommissionRateField");
        writer.StartObject();
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.InstrumentID);
        writer.Key("ClientID");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.ClientID);
        writer.Key("OpenRatioByMoney");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.OpenRatioByMoney);
        writer.Key("OpenRatioByVolume");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.OpenRatioByVolume);
        writer.Key("CloseRatioByMoney");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.CloseRatioByMoney);
        writer.Key("CloseRatioByVolume");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.CloseRatioByVolume);
        writer.Key("CloseTodayRatioByMoney");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.CloseTodayRatioByMoney);
        writer.Key("CloseTodayRatioByVolume");
        write_value(
            &writer,
            aRspInstrumentCommissionRateField.CloseTodayRatioByVolume);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcQryInstrumentStatusField const& aQryInstrumentStatusField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcQryInstrumentStatusField");
        writer.StartObject();
        writer.Key("InstIDStart");
        write_value(
            &writer,
            aQryInstrumentStatusField.InstIDStart);
        writer.Key("InstIDEnd");
        write_value(
            &writer,
            aQryInstrumentStatusField.InstIDEnd);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspInstrumentPriceField const& aRspInstrumentPriceField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspInstrumentPriceField");
        writer.StartObject();
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aRspInstrumentPriceField.InstrumentID);
        writer.Key("UpperLimitPrice");
        write_value(
            &writer,
            aRspInstrumentPriceField.UpperLimitPrice);
        writer.Key("LowerLimitPrice");
        write_value(
            &writer,
            aRspInstrumentPriceField.LowerLimitPrice);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcReqInstrumentPriceField const& aReqInstrumentPriceField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcReqInstrumentPriceField");
        writer.StartObject();
        writer.Key("ProductID");
        write_value(
            &writer,
            aReqInstrumentPriceField.ProductID);
        writer.Key("InstrumentID");
        write_value(
            &writer,
            aReqInstrumentPriceField.InstrumentID);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcInternalVersionIdentifyField const& aInternalVersionIdentifyField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcInternalVersionIdentifyField");
        writer.StartObject();
        writer.Key("VersionInfo");
        write_value(
            &writer,
            aInternalVersionIdentifyField.VersionInfo);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcExchangeIdentifyField const& aExchangeIdentifyField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcExchangeIdentifyField");
        writer.StartObject();
        writer.Key("ExchangeInfo");
        write_value(
            &writer,
            aExchangeIdentifyField.ExchangeInfo);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

inline std::ostream& operator<<(
    std::ostream& os,
    CXeleFtdcRspExchangeFrontField const& aRspExchangeFrontField) {  // NOLINT
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("CXeleFtdcRspExchangeFrontField");
        writer.StartObject();
        writer.Key("ExchangeID");
        write_value(
            &writer,
            aRspExchangeFrontField.ExchangeID);
        writer.Key("FrontCount");
        write_value(
            &writer,
            aRspExchangeFrontField.FrontCount);
        writer.Key("FrontList");
        write_value(
            &writer,
            aRspExchangeFrontField.FrontList);
        writer.EndObject();
    writer.EndObject();

    os <<sb.GetString();

    return os;
}

#endif

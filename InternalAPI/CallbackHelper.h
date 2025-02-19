/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\CallbackHelper.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once
#include <pybind11/functional.h>


#define ADD_FN_POINTER_CALLBACK_NO_PARAM(CallbackSetter, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)() = CallbackHelperNoParam<ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_ONE_PARAM(CallbackSetter, Type1, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1) = CallbackHelperOneParam<Type1, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_TWO_PARAMS(CallbackSetter, Type1, Type2, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2) = CallbackHelperTwoParams<Type1, Type2, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_THREE_PARAMS(CallbackSetter, Type1, Type2, Type3, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2, Type3) = CallbackHelperThreeParams<Type1, Type2, Type3, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(CallbackSetter, Type1, Type2, Type3, Type4, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2, Type3, Type4) = CallbackHelperFourParams<Type1, Type2, Type3, Type4, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(CallbackSetter, Type1, Type2, Type3, Type4, Type5, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2, Type3, Type4, Type5) = CallbackHelperFiveParams<Type1, Type2, Type3, Type4, Type5, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define ADD_FN_POINTER_CALLBACK_SIX_PARAMS(CallbackSetter, Type1, Type2, Type3, Type4, Type5, Type6, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2, Type3, Type4, Type5, Type6) = CallbackHelperSixParams<Type1, Type2, Type3, Type4, Type5, Type6, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }

#define ADD_FN_POINTER_CALLBACK_EIGHT_PARAMS(CallbackSetter, Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, ReturnType, P1Name, P2Name) \
    if (P1Name) \
    { \
        ReturnType(*callback)(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8) = CallbackHelperEightParams<Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, ReturnType>::SetCallback(P1Name, P2Name); \
        return CallbackSetter(callback); \
    } \
    else \
    { \
        return CallbackSetter(nullptr); \
    }


#define MAX_CALLBACK_COUNT 512
#define DEFINE_FN_POINTER_CALLBACKS(X) \
    switch (index) \
    { \
        X(0) X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31) X(32) X(33) X(34) X(35) X(36) X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) X(49) \
        X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) X(65) X(66) X(67) X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82) X(83) X(84) X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) \
        X(100) X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127) X(128) X(129) X(130) X(131) X(132) X(133) X(134) X(135) X(136) X(137) X(138) X(139) X(140) X(141) X(142) X(143) X(144) X(145) X(146) X(147) X(148) X(149) \
        X(150) X(151) X(152) X(153) X(154) X(155) X(156) X(157) X(158) X(159) X(160) X(161) X(162) X(163) X(164) X(165) X(166) X(167) X(168) X(169) X(170) X(171) X(172) X(173) X(174) X(175) X(176) X(177) X(178) X(179) X(180) X(181) X(182) X(183) X(184) X(185) X(186) X(187) X(188) X(189) X(190) X(191) X(192) X(193) X(194) X(195) X(196) X(197) X(198) X(199) \
        X(200) X(201) X(202) X(203) X(204) X(205) X(206) X(207) X(208) X(209) X(210) X(211) X(212) X(213) X(214) X(215) X(216) X(217) X(218) X(219) X(220) X(221) X(222) X(223) X(224) X(225) X(226) X(227) X(228) X(229) X(230) X(231) X(232) X(233) X(234) X(235) X(236) X(237) X(238) X(239) X(240) X(241) X(242) X(243) X(244) X(245) X(246) X(247) X(248) X(249) \
        X(250) X(251) X(252) X(253) X(254) X(255) X(256) X(257) X(258) X(259) X(260) X(261) X(262) X(263) X(264) X(265) X(266) X(267) X(268) X(269) X(270) X(271) X(272) X(273) X(274) X(275) X(276) X(277) X(278) X(279) X(280) X(281) X(282) X(283) X(284) X(285) X(286) X(287) X(288) X(289) X(290) X(291) X(292) X(293) X(294) X(295) X(296) X(297) X(298) X(299) \
        X(300) X(301) X(302) X(303) X(304) X(305) X(306) X(307) X(308) X(309) X(310) X(311) X(312) X(313) X(314) X(315) X(316) X(317) X(318) X(319) X(320) X(321) X(322) X(323) X(324) X(325) X(326) X(327) X(328) X(329) X(330) X(331) X(332) X(333) X(334) X(335) X(336) X(337) X(338) X(339) X(340) X(341) X(342) X(343) X(344) X(345) X(346) X(347) X(348) X(349) \
        X(350) X(351) X(352) X(353) X(354) X(355) X(356) X(357) X(358) X(359) X(360) X(361) X(362) X(363) X(364) X(365) X(366) X(367) X(368) X(369) X(370) X(371) X(372) X(373) X(374) X(375) X(376) X(377) X(378) X(379) X(380) X(381) X(382) X(383) X(384) X(385) X(386) X(387) X(388) X(389) X(390) X(391) X(392) X(393) X(394) X(395) X(396) X(397) X(398) X(399) \
        X(400) X(401) X(402) X(403) X(404) X(405) X(406) X(407) X(408) X(409) X(410) X(411) X(412) X(413) X(414) X(415) X(416) X(417) X(418) X(419) X(420) X(421) X(422) X(423) X(424) X(425) X(426) X(427) X(428) X(429) X(430) X(431) X(432) X(433) X(434) X(435) X(436) X(437) X(438) X(439) X(440) X(441) X(442) X(443) X(444) X(445) X(446) X(447) X(448) X(449) \
        X(450) X(451) X(452) X(453) X(454) X(455) X(456) X(457) X(458) X(459) X(460) X(461) X(462) X(463) X(464) X(465) X(466) X(467) X(468) X(469) X(470) X(471) X(472) X(473) X(474) X(475) X(476) X(477) X(478) X(479) X(480) X(481) X(482) X(483) X(484) X(485) X(486) X(487) X(488) X(489) X(490) X(491) X(492) X(493) X(494) X(495) X(496) X(497) X(498) X(499) \
        X(500) X(501) X(502) X(503) X(504) X(505) X(506) X(507) X(508) X(509) X(510) X(511) \
        default: \
            throw std::runtime_error("Set too many Callbacks!"); \
    }

#define MAX_CALLBACK_COUNT_20 20
#define DEFINE_FN_POINTER_CALLBACKS_20(X) \
    switch (index) \
    { \
        X(0) X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) \
        default: \
            throw std::runtime_error("Set too many Callbacks!"); \
    }


template <typename T1, typename T2>
int GetCallbackIndex(T1 callbackPtrs[], T2 callbackFuncs[], std::string callbackIDs[], T2 & fn, const std::string & fnID, int maxCallbackCount)
{
    assert(fn);
    for (int i = 0; i < maxCallbackCount; i++)
    {
        if (nullptr == callbackPtrs[i])
        {
            return i;
        }
        if (callbackIDs[i] == fnID)
        {
            assert(nullptr != callbackPtrs[i]);
            callbackFuncs[i] = fn;
            return i;
        }
    }
    throw std::runtime_error("Set too many Callbacks!");
}

template <typename T1, typename T2>
T2 GetOldCallbackFunctionTmplate(T1 callbackPtrs[], T2 callbackFuncs[], std::string callbackIDs[], T1 oldPtr, int maxCount)
{
    assert(oldPtr);
    for (int i = 0; i < maxCount; i++)
    {
        if (nullptr == callbackPtrs[i])
        {
            return nullptr;
        }
        if (callbackPtrs[i] == oldPtr)
        {
            return callbackFuncs[i];
        }
    }
    return nullptr;
}


template <typename RT>
class CallbackHelperNoParam {
public:
    typedef RT(*CallbackPtrTypeNoParam)();

#define DEFINE_FN_POINTER_CALLBACK_NO_PARAM(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = []() -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeNoParam SetCallback(std::function<RT()>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_NO_PARAM);
    }

private:
    static std::function<RT()> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeNoParam m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename RT>
std::function<RT()> CallbackHelperNoParam<RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename RT>
typename CallbackHelperNoParam<RT>::CallbackPtrTypeNoParam CallbackHelperNoParam<RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename RT>
std::string CallbackHelperNoParam<RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename RT>
class CallbackHelperOneParam {
public:
    typedef RT(*CallbackPtrTypeOneParam)(T1);

#define DEFINE_FN_POINTER_CALLBACK_ONE_PARAM(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeOneParam SetCallback(std::function<RT(T1)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_ONE_PARAM);
    }

private:
    static std::function<RT(T1)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeOneParam m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename RT>
std::function<RT(T1)> CallbackHelperOneParam<T1, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename RT>
typename CallbackHelperOneParam<T1, RT>::CallbackPtrTypeOneParam CallbackHelperOneParam<T1, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename RT>
std::string CallbackHelperOneParam<T1, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename RT>
class CallbackHelperTwoParams {
public:
    typedef RT(*CallbackPtrTypeTwoParams)(T1, T2);

#define DEFINE_FN_POINTER_CALLBACK_TWO_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeTwoParams SetCallback(std::function<RT(T1, T2)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_TWO_PARAMS);
    }

private:
    static std::function<RT(T1, T2)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeTwoParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename RT>
std::function<RT(T1, T2)> CallbackHelperTwoParams<T1, T2, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename RT>
typename CallbackHelperTwoParams<T1, T2, RT>::CallbackPtrTypeTwoParams CallbackHelperTwoParams<T1, T2, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename RT>
std::string CallbackHelperTwoParams<T1, T2, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename T3, typename RT>
class CallbackHelperThreeParams {
public:
    typedef RT(*CallbackPtrTypeThreeParams)(T1, T2, T3);

#define DEFINE_FN_POINTER_CALLBACK_THREE_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2, T3 p3) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2, p3); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeThreeParams SetCallback(std::function<RT(T1, T2, T3)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_THREE_PARAMS);
    }

private:
    static std::function<RT(T1, T2, T3)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeThreeParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename T3, typename RT>
std::function<RT(T1, T2, T3)> CallbackHelperThreeParams<T1, T2, T3, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename T3, typename RT>
typename CallbackHelperThreeParams<T1, T2, T3, RT>::CallbackPtrTypeThreeParams CallbackHelperThreeParams<T1, T2, T3, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename T3, typename RT>
std::string CallbackHelperThreeParams<T1, T2, T3, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename T3, typename T4, typename RT>
class CallbackHelperFourParams {
public:
    typedef RT(*CallbackPtrTypeFourParams)(T1, T2, T3, T4);

#define DEFINE_FN_POINTER_CALLBACK_FOUR_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2, T3 p3, T4 p4) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2, p3, p4); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeFourParams SetCallback(std::function<RT(T1, T2, T3, T4)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_FOUR_PARAMS);
    }

private:
    static std::function<RT(T1, T2, T3, T4)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeFourParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename T3, typename T4, typename RT>
std::function<RT(T1, T2, T3, T4)> CallbackHelperFourParams<T1, T2, T3, T4, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename T3, typename T4, typename RT>
typename CallbackHelperFourParams<T1, T2, T3, T4, RT>::CallbackPtrTypeFourParams CallbackHelperFourParams<T1, T2, T3, T4, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename T3, typename T4, typename RT>
std::string CallbackHelperFourParams<T1, T2, T3, T4, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename RT>
class CallbackHelperFiveParams {
public:
    typedef RT(*CallbackPtrTypeFiveParams)(T1, T2, T3, T4, T5);

#define DEFINE_FN_POINTER_CALLBACK_FIVE_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2, T3 p3, T4 p4, T5 p5) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2, p3, p4, p5); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeFiveParams SetCallback(std::function<RT(T1, T2, T3, T4, T5)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_FIVE_PARAMS);
    }

private:
    static std::function<RT(T1, T2, T3, T4, T5)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeFiveParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename RT>
std::function<RT(T1, T2, T3, T4, T5)> CallbackHelperFiveParams<T1, T2, T3, T4, T5, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename RT>
typename CallbackHelperFiveParams<T1, T2, T3, T4, T5, RT>::CallbackPtrTypeFiveParams CallbackHelperFiveParams<T1, T2, T3, T4, T5, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename RT>
std::string CallbackHelperFiveParams<T1, T2, T3, T4, T5, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename RT>
class CallbackHelperSixParams {
public:
    typedef RT(*CallbackPtrTypeSixParams)(T1, T2, T3, T4, T5, T6);

#define DEFINE_FN_POINTER_CALLBACK_SIX_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2, p3, p4, p5, p6); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeSixParams SetCallback(std::function<RT(T1, T2, T3, T4, T5, T6)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_SIX_PARAMS);
    }

private:
    static std::function<RT(T1, T2, T3, T4, T5, T6)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeSixParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename RT>
std::function<RT(T1, T2, T3, T4, T5, T6)> CallbackHelperSixParams<T1, T2, T3, T4, T5, T6, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename RT>
typename CallbackHelperSixParams<T1, T2, T3, T4, T5, T6, RT>::CallbackPtrTypeSixParams CallbackHelperSixParams<T1, T2, T3, T4, T5, T6, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename RT>
std::string CallbackHelperSixParams<T1, T2, T3, T4, T5, T6, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename RT>
class CallbackHelperEightParams {
public:
    typedef RT(*CallbackPtrTypeEightParams)(T1, T2, T3, T4, T5, T6, T7, T8);

#define DEFINE_FN_POINTER_CALLBACK_EIGHT_PARAMS(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8) -> RT \
        { \
            try \
            { \
                return m_callbackFuncs[index](p1, p2, p3, p4, p5, p6, p7, p8); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CallbackPtrTypeEightParams SetCallback(std::function<RT(T1, T2, T3, T4, T5, T6, T7, T8)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS(DEFINE_FN_POINTER_CALLBACK_EIGHT_PARAMS);
    }

private:
    static std::function<RT(T1, T2, T3, T4, T5, T6, T7, T8)> m_callbackFuncs[MAX_CALLBACK_COUNT];
    static CallbackPtrTypeEightParams m_callbackPtrs[MAX_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT];
};
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename RT>
std::function<RT(T1, T2, T3, T4, T5, T6, T7, T8)> CallbackHelperEightParams<T1, T2, T3, T4, T5, T6, T7, T8, RT>::m_callbackFuncs[MAX_CALLBACK_COUNT];
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename RT>
typename CallbackHelperEightParams<T1, T2, T3, T4, T5, T6, T7, T8, RT>::CallbackPtrTypeEightParams CallbackHelperEightParams<T1, T2, T3, T4, T5, T6, T7, T8, RT>::m_callbackPtrs[MAX_CALLBACK_COUNT] = { 0 };
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename RT>
std::string CallbackHelperEightParams<T1, T2, T3, T4, T5, T6, T7, T8, RT>::m_callbackIDs[MAX_CALLBACK_COUNT];


class TaskChangingCallbackHelper
{
public:
    typedef void(*TaskChangingCallbackPtrType)(bool*, WCharCP, WCharCP);

#define MAX_TASK_CHANGING_CALLBACK_COUNT 10
#define DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](bool* cancelTaskChange, WCharCP currentPath, WCharCP newPath) \
        { \
            try \
            { \
                return m_callbackFuncs[index]((BoolWrapper*)cancelTaskChange, currentPath, newPath); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static TaskChangingCallbackPtrType SetCallback(std::function<void(BoolWrapper*, WCharCP, WCharCP)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_TASK_CHANGING_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(0);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(1);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(2);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(3);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(4);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(5);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(6);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(7);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(8);
            DEFINE_FN_POINTER_TASK_CHANGING_CALLBACK(9);
        default:
            throw std::runtime_error("Set too many Callbacks for TaskNavigationTaskChanging!");
        }
    }

private:
    static std::function<void(BoolWrapper*, WCharCP, WCharCP)> m_callbackFuncs[MAX_TASK_CHANGING_CALLBACK_COUNT];
    static TaskChangingCallbackPtrType m_callbackPtrs[MAX_TASK_CHANGING_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_TASK_CHANGING_CALLBACK_COUNT];
};

class ChangeTrackFunc_XAttributeChangedHelper
{
public:
    typedef void(*ChangeTrackFunc_XAttributeChangedPtrType)(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, bool*);

#define MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT 10
#define DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](XAttributeHandleCP xAttr, DgnPlatform::ChangeTrackInfo* info, bool* cantBeUndoneFlag) \
        { \
            try \
            { \
                return m_callbackFuncs[index](xAttr, info, (BoolWrapper*)cantBeUndoneFlag); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ChangeTrackFunc_XAttributeChangedPtrType SetCallback(std::function<void(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(0);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(1);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(2);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(3);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(4);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(5);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(6);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(7);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(8);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_XATTRIBUTECHANGED(9);
        default:
            throw std::runtime_error("Set too many Callbacks for ChangeTrackFunc_XAttributeChanged!");
        }
    }

private:
    static std::function<void(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)> m_callbackFuncs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT];
    static ChangeTrackFunc_XAttributeChangedPtrType m_callbackPtrs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT];
    static std::string m_callbackIDs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT];
};

class ChangeTrackFunc_ChangedHelper
{
public:
    typedef void(*ChangeTrackFunc_ChangedPtrType)(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, bool*);

#define MAX_CHANGETRACKFUNC_CHANGED_COUNT 10
#define DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](MSElementDescrP newDescr, MSElementDescrP oldDescr, DgnPlatform::ChangeTrackInfo* info, bool* cantBeUndoneFlag) \
        { \
            try \
            { \
                return m_callbackFuncs[index](newDescr, oldDescr, info, (BoolWrapper*)cantBeUndoneFlag); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ChangeTrackFunc_ChangedPtrType SetCallback(std::function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CHANGETRACKFUNC_CHANGED_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(0);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(1);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(2);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(3);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(4);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(5);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(6);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(7);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(8);
            DEFINE_FN_POINTER_CHANGETRACKFUNC_CHANGED(9);
        default:
            throw std::runtime_error("Set too many Callbacks for ChangeTrackFunc_Changed!");
        }
    }

private:
    static std::function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)> m_callbackFuncs[MAX_CHANGETRACKFUNC_CHANGED_COUNT];
    static ChangeTrackFunc_ChangedPtrType m_callbackPtrs[MAX_CHANGETRACKFUNC_CHANGED_COUNT];
    static std::string m_callbackIDs[MAX_CHANGETRACKFUNC_CHANGED_COUNT];
};

class OverridePathDescriptionCallbackHelper {
public:
    typedef void(*OverridePathDescriptionCallbackPtrType)(DisplayPathCP, WStringR);
    typedef std::function<void(DisplayPathCP, WString*)> OverridePathDescriptionFunctionType;

#define MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT 20
#define DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](DisplayPathCP path, WStringR description) \
        { \
            try \
            { \
                m_callbackFuncs[index](path, &description); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static OverridePathDescriptionCallbackPtrType SetCallback(OverridePathDescriptionFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(0);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(1);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(2);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(3);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(4);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(5);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(6);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(7);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(8);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(9);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(10);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(11);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(12);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(13);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(14);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(15);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(16);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(17);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(18);
            DEFINE_FN_POINTER_OVERRIDE_PATH_DESCRIPTION_CALLBACK(19);
        default:
            throw std::runtime_error("Set too many Callbacks for OverridePathDescriptionCallbackHelper!");
        }
    }

    static OverridePathDescriptionFunctionType GetOldCallbackFunction(OverridePathDescriptionCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT);
    }

private:
    static OverridePathDescriptionFunctionType m_callbackFuncs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT];
    static OverridePathDescriptionCallbackPtrType m_callbackPtrs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT];
};

class CompressDgnFileCallbackHelper {
public:
    typedef StatusInt(*CompressDgnFileCallbackPtrType)(WCharP, CompressType);
    typedef std::function<StatusInt(WString*, CompressType)> CompressDgnFileFunctionType;

#define MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT 20
#define DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](WCharP errorMessage, CompressType type) \
        { \
            try \
            { \
                WString message; \
                StatusInt returnVal = m_callbackFuncs[index](&message, type); \
                wcscpy(errorMessage, message.GetWCharCP()); \
                return returnVal; \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static CompressDgnFileCallbackPtrType SetCallback(CompressDgnFileFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(0);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(1);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(2);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(3);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(4);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(5);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(6);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(7);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(8);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(9);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(10);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(11);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(12);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(13);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(14);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(15);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(16);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(17);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(18);
            DEFINE_FN_POINTER_COMPRESS_DGN_FILE_CALLBACK(19);
        default:
            throw std::runtime_error("Set too many Callbacks for CompressDgnFileCallbackHelper !");
        }
    }

    static CompressDgnFileFunctionType GetOldCallbackFunction(CompressDgnFileCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT);
    }

private:
    static CompressDgnFileFunctionType m_callbackFuncs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT];
    static CompressDgnFileCallbackPtrType m_callbackPtrs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT];
};

class ElmDscrCopyCallbackHelper {
public:
    typedef void(*ElmDscrCopyCallbackPtrType)(EditElementHandleR, DgnModelRefP, DgnModelRefP, bool);
    typedef std::function<void(EditElementHandle*, DgnModelRefP, DgnModelRefP, bool)> ElmDscrCopyFunctionType;

#define MAX_ELM_DSCR_COPY_CALLBACK_COUNT 20
#define DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](EditElementHandleR eeh, DgnModelRefP sourceModelRef, DgnModelRefP destModelRef, bool preCopy) \
        { \
            try \
            { \
                m_callbackFuncs[index](&eeh, sourceModelRef, destModelRef, preCopy); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ElmDscrCopyCallbackPtrType SetCallback(ElmDscrCopyFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_ELM_DSCR_COPY_CALLBACK_COUNT);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }

        switch (index)
        {
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(0);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(1);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(2);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(3);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(4);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(5);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(6);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(7);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(8);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(9);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(10);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(11);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(12);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(13);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(14);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(15);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(16);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(17);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(18);
            DEFINE_FN_POINTER_ELM_DSCR_COPY_CALLBACK(19);
        default:
            throw std::runtime_error("Set too many Callbacks for ElmDscrCopyCallbackHelper !");
        }
    }

    static ElmDscrCopyFunctionType GetOldCallbackFunction(ElmDscrCopyCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_ELM_DSCR_COPY_CALLBACK_COUNT);
    }

private:
    static ElmDscrCopyFunctionType m_callbackFuncs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT];
    static ElmDscrCopyCallbackPtrType m_callbackPtrs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT];
    static std::string m_callbackIDs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT];
};

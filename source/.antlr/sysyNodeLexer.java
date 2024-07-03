// Generated from /home/william/compiler/MyCompiler/source/sysyNode.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class sysyNodeLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T_NUM_VALUE=1, T_OPERATOR=2;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T_NUM_VALUE", "T_OPERATOR"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "T_NUM_VALUE", "T_OPERATOR"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public sysyNodeLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "sysyNode.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0002\u001d\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0001\u0000\u0001\u0000\u0005\u0000\b\b\u0000\n\u0000"+
		"\f\u0000\u000b\t\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001"+
		"\u001c\b\u0001\u0000\u0000\u0002\u0001\u0001\u0003\u0002\u0001\u0000\u0004"+
		"\u0001\u000019\u0001\u000009\u0003\u0000*+--//\u0002\u0000<<>>%\u0000"+
		"\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0001"+
		"\u0005\u0001\u0000\u0000\u0000\u0003\u001b\u0001\u0000\u0000\u0000\u0005"+
		"\t\u0007\u0000\u0000\u0000\u0006\b\u0007\u0001\u0000\u0000\u0007\u0006"+
		"\u0001\u0000\u0000\u0000\b\u000b\u0001\u0000\u0000\u0000\t\u0007\u0001"+
		"\u0000\u0000\u0000\t\n\u0001\u0000\u0000\u0000\n\u0002\u0001\u0000\u0000"+
		"\u0000\u000b\t\u0001\u0000\u0000\u0000\f\u001c\u0007\u0002\u0000\u0000"+
		"\r\u000e\u0005&\u0000\u0000\u000e\u001c\u0005&\u0000\u0000\u000f\u0010"+
		"\u0005|\u0000\u0000\u0010\u001c\u0005|\u0000\u0000\u0011\u0012\u0005!"+
		"\u0000\u0000\u0012\u001c\u0005=\u0000\u0000\u0013\u0014\u0005=\u0000\u0000"+
		"\u0014\u001c\u0005=\u0000\u0000\u0015\u001c\u0007\u0003\u0000\u0000\u0016"+
		"\u0017\u0005>\u0000\u0000\u0017\u001c\u0005=\u0000\u0000\u0018\u0019\u0005"+
		"<\u0000\u0000\u0019\u001c\u0005=\u0000\u0000\u001a\u001c\u0005!\u0000"+
		"\u0000\u001b\f\u0001\u0000\u0000\u0000\u001b\r\u0001\u0000\u0000\u0000"+
		"\u001b\u000f\u0001\u0000\u0000\u0000\u001b\u0011\u0001\u0000\u0000\u0000"+
		"\u001b\u0013\u0001\u0000\u0000\u0000\u001b\u0015\u0001\u0000\u0000\u0000"+
		"\u001b\u0016\u0001\u0000\u0000\u0000\u001b\u0018\u0001\u0000\u0000\u0000"+
		"\u001b\u001a\u0001\u0000\u0000\u0000\u001c\u0004\u0001\u0000\u0000\u0000"+
		"\u0003\u0000\t\u001b\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}